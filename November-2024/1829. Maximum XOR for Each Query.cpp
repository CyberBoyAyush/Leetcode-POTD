class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
       int n = nums.size();

       vector<int> result(n);

       // step 1 : find XOR total
       int XOR = 0;

       for(int i = 0; i<n ; i++){
            XOR ^= nums[i];
       } 

       // step 2 : find flip from mask where all set bits are 1
        int mask = ((1<<maximumBit) - 1); // 2 ^ maximumBit - 1

        for(int i = 0; i<n ; i++){
            int ans = XOR ^ mask; // flipped values
            result[i] = (ans);

            // removing last element for next query
            XOR ^= nums[n-i-1];
        }

        return result;
    }
};
