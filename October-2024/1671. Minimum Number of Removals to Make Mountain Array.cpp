// Approach - DP (LIS and LDS)
// TC - O(n^2)
// SC - O(n)

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        // LIS and LDS
        vector<int> LIS(n,1);
        vector<int> LDS(n,1);

        // calcualting LIS
        for(int i = 0 ; i< n ; i++){
            for(int j = 0; j<i ; j++){
                if(nums[i] > nums[j]){
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        // calcuating LDS
        for(int i = n-1; i>=0 ; i--){
            for(int j = i+1; j<n ;j++){
                if(nums[i] > nums[j]){
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        int minRemovals = INT_MAX;
        for(int i = 0; i< n ; i++){
            if (LIS[i] > 1 && LDS[i] > 1) { // Valid mountain peak
                minRemovals = min(minRemovals, n - (LIS[i] + LDS[i] - 1));
            }
        }

        return minRemovals;
    }
};
