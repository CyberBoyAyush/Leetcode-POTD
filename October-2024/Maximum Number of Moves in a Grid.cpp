class Solution {
public:
    int n, m;

    vector<int> directions = {-1,0,1};

    int DFS(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){
        int moves = 0;

        // memorize
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        for(auto &dir : directions){
            int row = i + dir;
            int col = j + 1;

            if (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] > grid[i][j]) {
                moves = max(moves, 1 + DFS(row, col, grid,dp));
            }
        }

        return dp[i][j] = moves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();         
        n = grid[0].size();   

        vector<vector<int>> dp(m , vector<int>(n, -1)); 

        int result = 0;
        for (int row = 0; row < m; row++) {
            result = max(result, DFS(row, 0, grid,dp));
        }

        return result;
    }
};
