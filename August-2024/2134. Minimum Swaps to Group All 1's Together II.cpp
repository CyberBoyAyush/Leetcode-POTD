class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // To find the 1 in nums we can find its sum as it only contains 0 and 1
        int totalOnes = accumulate(begin(nums), end(nums) , 0);

        // Now applying sliding window
        int i = 0; 
        int j = 0;
        int currCount = 0;
        int maxCount = 0;

        while(j < 2*n - 1){
            // we are running j to 2*n -1 to simulate circular matrix
            if(nums[j%n] == 1){
                currCount++;
            }

            if(j - i + 1 > totalOnes){
                // sliding window gets exceeded shrink it
                currCount -= nums[i%n];
                i++; // shrinks window
            }

            // calculating maxCount
            maxCount = max(maxCount , currCount);
            j ++ ; // expands the window
        }
        
        return totalOnes - maxCount; // The Swaps we needed
    }
};
