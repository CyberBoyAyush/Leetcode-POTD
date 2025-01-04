class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long tSum = 0;

        for(auto &num:nums){
            tSum += num;
        }

        long long leftSum = 0;

        long long rightSum = 0;

        long long split = 0;

        for(int i = 0; i<n-1; i++){
            leftSum += nums[i];

            rightSum = tSum - leftSum;

            if(leftSum >= rightSum){
                split++;
            }
        }

        return split;
    }
};
