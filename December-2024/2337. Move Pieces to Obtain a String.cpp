// Recursion + Memo -> TLE
class Solution {
public:
    int n;
    bool solve(string &start, string &target, unordered_map<string, bool>& memo){
        if(start == target){
            return true;// we found the ans
        }

        if(memo.count(start) != 0){
            // we have seen this state call memo
            return memo[start];
        }

        for(int i = 0; i<start.length(); i++){
            if(start[i] == 'L' && i>0 && start[i-1] == '_'){
                swap(start[i], start[i-1]); // L is there and blank space on i - 1 so swap it
                if(solve(start,target,memo) == true){
                    return true;
                }

                // swap again for recursive call
                // undo changes
                swap(start[i], start[i-1]);
            }

            else if(start[i] == 'R' && i<n-1 && start[i+1] == '_'){
                swap(start[i], start[i+1]); // R is there and blank space on i + 1 so swap it
                if(solve(start,target,memo) == true){
                    return true;
                }

                // swap again for recursive call
                // undo changes
                swap(start[i], start[i+1]);
            }
        }

        return memo[start] = false;
    }
    bool canChange(string start, string target) {
        n = start.length();
        unordered_map<string, bool> memo; // to memoize result
        return solve(start, target, memo);
    }
};


// Two Pointer + Observation
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int i = 0;
        int j = 0;

        while(i<n ||  j<n){
            while(i<n && start[i] == '_'){
                i++;
            }
            while(j<n && target[j] == '_'){
                j++;
            }

            if(i == n || j == n){
                return i == n && j == n; // if both strings ended it means true else it means false as one string has ended before
            }

            if(start[i] != target[j]){
                return false; // char not matched
            }

            if(start[i] == 'L' && i<j){
                return false;
            }

            if(start[i] == 'R' && i>j){
                return false;
            }

            i++;
            j++;

        }

        return true;
    }
};
