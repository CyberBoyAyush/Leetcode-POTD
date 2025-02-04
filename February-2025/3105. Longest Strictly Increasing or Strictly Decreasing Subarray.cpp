class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int res = 1;

        int inc = 1;

        int dec = 1;

        for(int i=1; i<n ; i++){
            if(nums[i] > nums[i-1]){
                // inc
                inc++;
                dec = 1;
                res = max(res, inc);
            }
            else if(nums[i]<nums[i-1]){
                // dec
                dec++;
                inc = 1;
                res = max(res,dec);
            }
            else{
                // same
                inc = 1;
                dec = 1;
            }
        }

        return res;
    }
};
