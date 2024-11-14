// count-square-submatrices-with-all-ones
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

#include <bits/stdc++.h>
using namespace std;

// Bottom's Up -> Tabulation using maximal square approach
// TC : O(n*m)
// SC : O(n*m)

class Solution {
public:
    int countSquares(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> dp(n, vector<int> (m,0));

        for(int j = 0; j<m ; j++){ // setting col 0 as same as matrix
            dp[0][j] = arr[0][j];
        }

        for(int i = 0; i<n ; i++){ // setting row 0 as same as matrix
            dp[i][0] = arr[i][0];
        }

        for(int i = 1; i<n ;i++){
            for(int j = 1; j<m; j++){
                if(arr[i][j] == 0){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                }
            }
        }

        int sum = 0;

        for(int i = 0; i<n ;i++){
            for(int j = 0; j<m ; j++){
                sum += dp[i][j];
            }
        }

        return sum;
    }
};

// Recursive + Memoization
// TC : O(n*m)
// SC : O(n*m)

class Solution {
public:
    int n, m;
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(i >= n || j >= m) return 0;

        if(grid[i][j] == 0) return 0;

        if(dp[i][j] != -1){
             return dp[i][j];
        }

        // right
        int right = solve(i, j+1, grid, dp);
        // diagnol
        int diag = solve(i+1, j+1, grid, dp);
        // below
        int below = solve(i+1, j, grid, dp);

        return dp[i][j] = 1 + min({right, diag, below});
    }
    int countSquares(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int result = 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int i = 0; i< n; i++){
            for(int j = 0; j<m ; j++){
                result += solve(i,j,grid,dp);
            }
        }

        return result;
    }
};

// Recursive
// TC : O(3^n)
// SC : O(n)

class Solution {
public:
    int n, m;
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i >= n || j >= m) return 0;

        if(grid[i][j] == 0) return 0;

        // right
        int right = solve(i, j+1, grid);
        // diagnol
        int diag = solve(i+1, j+1, grid);
        // below
        int below = solve(i+1, j, grid);

        return 1 + min({right, diag, below});
    }
    int countSquares(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int result = 0;

        for(int i = 0; i< n; i++){
            for(int j = 0; j<m ; j++){
                result += solve(i,j,grid);
            }
        }

        return result;
    }
};
