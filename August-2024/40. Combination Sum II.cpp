class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target,vector<vector<int>> &result
    ,vector<int> &curr){
        if(target < 0){
            return;
        }
        if(target == 0){
            result.push_back(curr);
        }

        for(int i = idx; i<candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1]){
                // duplicate found
                continue;
            }

            curr.push_back(candidates[i]); // do it
            solve(i+1,candidates,target - candidates[i],result,curr); // explore
            curr.pop_back(); // undo
        }

    } 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        vector<int> curr; // store the curr

        // we sort the array to deal with duplicates
        sort(candidates.begin(),candidates.end());

        solve(0,candidates,target,result,curr);

        return result;
    }
};
