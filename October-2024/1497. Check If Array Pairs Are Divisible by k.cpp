class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k,0);

        // finding remainder
        for(auto num : arr){
            int rem = (num % k + k) % k; // as number can also be nagitve
            mp[rem]++;
        }

        // edge case if all el are divisible alreadt
        if(mp[0] % 2 != 0){
            return false;
        }

        for(int i = 1; i<=k/2 ; i++){
            int counterHalf = k - i;
            if(mp[counterHalf] != mp[i]){
                return false;
            }
        }

        return true;
    }
};
