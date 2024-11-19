class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        int j = 0;

        unordered_set<int> st;

        long long result = 0;

        long long currWindowSum = 0;

        while(j < n){
            // check if already in set(for duplicate)
            while(st.count(nums[j])){
                // present
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            currWindowSum += nums[j];
            st.insert(nums[j]);


            // checking window size equals k
            if(j - i + 1 == k){
                result = max(result, currWindowSum);

                // shrink window from left
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            j++;
        }
        return result;
    }
};
