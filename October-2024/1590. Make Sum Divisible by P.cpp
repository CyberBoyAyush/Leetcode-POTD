class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        // finding total sum
        long long totalSum = 0;

        for(int i : nums){
            totalSum += i;
        }

        // target
        int target = totalSum % p;

        // edge case
        if(target == 0){
            return 0;
        }

        // map
        unordered_map<int,int> mp; // we store sum%p and index here
        int res = INT_MAX;
        int curr = 0;
        mp[0] = -1; // initial entry in map

        for(int j = 0; j<n ; j++){
            curr = (curr + nums[j]) % p;

            int find = (curr - target + p) % p;

            if(mp.find(find) != mp.end()){
                // found
                res = min(res, j-mp[find]);
            }

            mp[curr] = j;
        }

        return res == n ? -1 : res;


    }
};
