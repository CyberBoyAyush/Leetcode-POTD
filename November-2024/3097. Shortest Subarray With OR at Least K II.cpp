class Solution {
public:
    void addinWin(int num,vector<int> &bits){ // O(32)
        for(int i = 0; i<32; i++){
            if((num >> i) & 1){
                // bit is set there
                bits[i]++;
            }
        }
    }

    void removeFromWin(int num, vector<int> &bits){ // O(32)
        for(int i = 0; i<32; i++){
            if((num >> i) & 1){
                // bit is set there
                bits[i]--;
            }
        }
    }

    int getDecimal(vector<int> &bits){ // O(32)
        int num = 0;

        for(int i = 0; i<32 ; i++){
            if(bits[i] > 0){
                // means bits is set in there
                num |= (1 << i); // num = num | (1<<i)
            }
        }

        return num;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int result = INT_MAX;

        vector<int> bits(32 , 0); 
        // bits[i] == total numbers of number which has their bit set at i th pos

        int i = 0;
        int j = 0;

        while(j<n){ // O(2 * n)
            // add number in window
            addinWin(nums[j], bits);

            while(i <= j && getDecimal(bits) >= k){
                // shrink window
                result = min(result, j-i+1);
                removeFromWin(nums[i],bits);
                i++; // window shrinked
            }

            j++;
        }
        return result == INT_MAX ? -1 : result;
    }
};
