class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = 0;
        int result = 0;
        int streak = 0;

        for(auto num : nums){
            if(num > maxValue){
                maxValue = num;
                result = 0;
                streak = 0;
            }

            if(maxValue == num){
                streak++;
            }
            else{
                streak = 0;
            }

            result = max(result,streak);
        }

        return result;
    }
};
