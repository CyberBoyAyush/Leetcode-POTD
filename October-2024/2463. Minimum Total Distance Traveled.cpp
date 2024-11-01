// minimum-total-distance-traveled
// Leetcode : https://leetcode.com/problems/minimum-total-distance-traveled/

#include <bits/stdc++.h>
using namespace std;

// Approach : Memoization Classic DP Take and Not Take
// Time Complexity : O(N x N)
// Space Complexity : O(N x N) + O(N)

class Solution {
public:
    long long solve(int i , int j, vector<int>& robot, vector<int>& positions, vector<vector<long long>> &dp){
        if(i >= robot.size()){
            return 0;
        }
        
        if(j >= positions.size()){
            // invalid case
            return 1e12;
        }

        // dp call
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        long long take = abs(positions[j] - robot[i]) + solve(i+1,j+1,robot,positions,dp);
        long long notTake = solve(i, j+1, robot,positions,dp);

        return dp[i][j] = min(take, notTake);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Step 1 - sorting both arrays
        sort(robot.begin(),robot.end());
        sort(factory.begin(), factory.end());

        // Step 2 -> expand the factory array for simplified use of it
        vector<int> positions;
        for(int i = 0 ; i<factory.size(); i++){
            int limit = factory[i][1];
            int pos = factory[i][0];

            for(int j = 0; j < limit; j++){
                positions.push_back(pos);
            }
        }

        vector<vector<long long>> dp(robot.size(), vector<long long>(positions.size(),-1));

        // Step 3 -> solve
        return solve(0,0,robot,positions,dp);
    }
};

// Approach : Tabulation Classic DP Take and Not Take
// Time Complexity : O(N x N)
// Space Complexity : O(N x N) + O(N)

// Zero base case initialization
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Step 1 - sorting both arrays
        sort(robot.begin(),robot.end());
        sort(factory.begin(), factory.end());

        // Step 2 -> expand the factory array for simplified use of it
        vector<int> positions;
        for(int i = 0 ; i<factory.size(); i++){
            int limit = factory[i][1];
            int pos = factory[i][0];

            for(int j = 0; j < limit; j++){
                positions.push_back(pos);
            }
        }

        int n = robot.size(), m = positions.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e12));

        // Base case: When all robots have been assigned, the distance is 0
        for (int j = 0; j <= m; j++) {
            dp[n][j] = 0;
        }

        // Fill dp table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // Option 1: Take the current factory position for the robot
                long long take = abs(positions[j] - robot[i]) + dp[i + 1][j + 1];

                // Option 2: Skip the current factory position
                long long notTake = dp[i][j + 1];

                // Choose the minimum distance
                dp[i][j] = min(take, notTake);
            }
        }
        
        return dp[0][0];
    }
};
