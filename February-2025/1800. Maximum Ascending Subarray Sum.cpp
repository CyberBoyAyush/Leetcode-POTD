class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int maxSum = 0;

        int currSum = nums[0];

        for(int i = 1;i<n ; i++){
            if(nums[i]> nums[i-1]){
                // increasing
                currSum += nums[i];
            }
            else{
                maxSum = max(maxSum, currSum);// updating maxSUm
                currSum = nums[i]; // moving it (starting from here now)
            }
        }

        return max(maxSum, currSum);
    }
};
