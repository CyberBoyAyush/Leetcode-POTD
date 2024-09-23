// Extra Characters in a String
// Leetcode : https://leetcode.com/problems/extra-characters-in-a-string/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution {
public:
    int solve(int i, string s, unordered_set<string> &st, int &n){
        if(i==n){
            return 0;
        }

        // either we skip the ith char
        int result = 1 + solve(i+1,s,st,n);

        // not skip so we create substring
        for(int j = i ; j<n; j++){
            string curr = s.substr(i,j-i+1);
            if(st.find(curr) != st.end()){
                // found it
                result = min(result, solve(j+1,s,st,n));
            }
        }

        return result;
    }
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();
        unordered_set<string> st(dict.begin(),dict.end());

        return solve(0,s,st,n);
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n^3)
// Space Complexity : O(Total char in dict) + O(n) for recursive stack

class Solution {
public:
    int dp[51];
    int solve(int i, string s, unordered_set<string> &st, int &n){
        if(i==n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        // either we skip the ith char
        int result = 1 + solve(i+1,s,st,n);

        // not skip so we create substring
        for(int j = i ; j<n; j++){
            string curr = s.substr(i,j-i+1);
            if(st.find(curr) != st.end()){
                // found it
                result = min(result, solve(j+1,s,st,n));
            }
        }

        return dp[i] = result;
    }
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();
        unordered_set<string> st(dict.begin(),dict.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,s,st,n);
    }
};

// Approach 3 : Bottom Up DP -> Tabulation
// Time Complexity : O(n^3)
// Space Complexity : O(n)

class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();
        unordered_set<string> st(dict.begin(),dict.end());
        vector<int> dp(n+1,0);

        // initization and filling all
        for(int i = n-1; i>=0; i--){
            // skip case
            dp[i] = 1 + dp[i+1];

            // finding substr
            for(int j = i ; j<n; j++){
            string curr = s.substr(i,j-i+1);
            if(st.find(curr) != st.end()){
                // found it
                dp[i] = min(dp[i], dp[j+1]);
            }
        }
        }
        return dp[0];
    }
};
