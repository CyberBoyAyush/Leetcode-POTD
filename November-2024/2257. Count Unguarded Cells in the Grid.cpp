class Solution {
public:
    void dfs(int row, int col,vector<vector<int>> &grid, int m , int n, int dir){
        if(row < 0 || row>=m || col<0 || col>=n || grid[row][col] == 1 || grid[row][col] == 2 ){
            return;
        }

        // mark as 3 -> visited
        grid[row][col] = 3;

        // rec call on based on dir -> UP, down, left and right
        if(dir == 1){
            // UP
            dfs(row-1,col,grid,m,n,1);
        }
        else if(dir == 2){
            // down
            dfs(row+1,col,grid,m,n,2);
        }
        else if(dir == 3){
            // left
            dfs(row,col-1,grid,m,n,3);
        }
        else{
            // right
            dfs(row,col + 1,grid,m,n,4);
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int> (n,0)); //m x n grid

        // makring guard cells as 1
        for(auto &guard : guards){
            int i = guard[0];
            int j = guard[1];

            grid[i][j] = 1;
        }

        //makring walls as 2
        for(auto &wall : walls){
            int i = wall[0];
            int j = wall[1];

            grid[i][j] = 2; 
        }

        // now using dfs we mark guagrded cells as 3
        for(auto &guard : guards){
            int gRow = guard[0];
            int gCol = guard[1];

            // 4 direction call -> Up, down, left, right
            dfs(gRow-1,gCol,grid,m,n,1); // up
            dfs(gRow+1,gCol,grid,m,n,2); // down
            dfs(gRow,gCol-1,grid,m,n,3); // left
            dfs(gRow,gCol+1,grid,m,n,4); // right

        }

        // counting 0 cells as they are unguardded
        int notGuarded = 0;

        for(int i = 0; i<m ; i++){
            for(int j = 0; j<n ; j++){
                if(grid[i][j] == 0){
                    notGuarded++;
                }
            }
        }

        return notGuarded;

    }
};
