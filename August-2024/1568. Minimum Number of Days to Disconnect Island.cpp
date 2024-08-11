class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m;
    int n;
    void DFS(vector<vector<int>> &grid , int i, int j,vector<vector<bool>>&vis){

        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] == 1 || grid[i][j] == 0){
            return ;
        }

        vis[i][j] = 1; // marking it visited

        // Calling neighbours
        for(auto &dir:directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            DFS(grid,new_i,new_j,vis);
        }

    }
    int noOfIslands(vector<vector<int>> &grid){
        int islandsCnt = 0;

        vector<vector<bool>> vis(m , vector<bool>(n));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n ; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    DFS(grid,i,j,vis);
                    islandsCnt++;
                }
            }
        }
        return islandsCnt;
    }
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int islands = noOfIslands(grid);

        if(islands > 1 || islands == 0){
            return 0; // we need 0 days
        }

        // now we check by converting each to 0 and check
        for(int i = 0; i<m ; i++){
            for(int j = 0; j<n ; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0; // marking it water 
                    islands = noOfIslands(grid);

                    grid[i][j] = 1; // remarking it as land for future check
                    if(islands > 1 || islands == 0){
                        return 1;
                    }
                }
            }
        }

        return 2; // we can always break any island in 2 days
    }
};
