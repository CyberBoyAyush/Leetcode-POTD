class Solution {
public:
    bool isPrime[1000];

    void sieve() { //O(1)
        fill(isPrime, isPrime+1000, true); //initiliase the array ith all True
        isPrime[0] = false; //0 is not a prime number
        isPrime[1] = false; //1 is not a prime number
        
        for(int i = 2; i < 1000; i++) {
            if(isPrime[i] == true) {
                for(int j = i*i; j < 1000; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();

        sieve();

        // we start checking from back as it will be more efficient
        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                continue;
            }

            // nums[i] >= nums[i+1]

            // check and deplete with prime no
            for(int p = 2; p<nums[i]; p++){
                if(!isPrime[p]){
                    // p is not prime no
                    continue;
                }

                if(nums[i] - p < nums[i+1]){
                    nums[i] -= p;
                    break;
                }
            }

            if(nums[i] >= nums[i+1]){
                // even it is greater after decreasing
                return false;
            }
        }
        return true;    
    }
};
