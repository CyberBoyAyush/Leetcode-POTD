class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    void DFS(int i, int j,vector<vector<int>> &matrix){
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == 1)
            return;

        
        matrix[i][j] = 1; // marking it visited

        for(const auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            DFS(new_i, new_j, matrix);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int regions = 0; // our final ans

        vector<vector<int>> matrix(rows*3 , vector<int>(cols*3 , 0));

        // Populating matrix acc to the signs we get  '/', '\'

        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols ; j++){
                if(grid[i][j] == '/'){
                    // we do antidiagnol
                    matrix[i*3][j*3+2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                }
                
                else if(grid[i][j] == '\\'){
                    // we do diagnol
                    matrix[i*3][j*3] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3+2] = 1;
                }
            }
        }

        // We apply DFS where it is 0
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size() ; j++){
                if(matrix[i][j] == 0){
                    // DFS HIT MARDO
                    DFS(i,j,matrix);
                    regions++;
                }
            }
        }

        return regions;
    }
};
