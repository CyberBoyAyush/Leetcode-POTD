class Solution {
public:
    bool isPossible(int mid,vector<int>& nums, int maxOp){
        int totalOp = 0;

        for(auto &num:nums){
            int operations = num/mid; // it calcaulated operations

            if(num % mid == 0){
                // it is divisiby by mid tha we need 1 less operation
                operations -= 1;
            }

            totalOp += operations;
        }

        return totalOp <= maxOp;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int res = 0;

        while(l<=r){
            int mid = (l + r) / 2;

            if(isPossible(mid, nums, maxOperations)){
                res = mid;
                r = mid - 1 ; // bcz we need to minimize the max
            }
            else{
                l = mid + 1;
            }
        }

        return res;
    }
};
