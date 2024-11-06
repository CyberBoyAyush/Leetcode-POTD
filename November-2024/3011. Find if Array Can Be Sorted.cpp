// Approach 1 -> Modified Bubble sort
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        bool swapped = true; // flag for optimized code

        // bubble sort algo
        for(int i = 0; i<n; i++){
            swapped = false; // setting it false for every iteration
            for(int j = 0; j<n-i-1; j++){
                // when no swap
                if(nums[j] <= nums[j+1]){
                    // no swap is needed as already sorted
                    continue;
                }
                else{
                    // swap is required
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1])){
                        // swap can happen
                        swap(nums[j], nums[j+1]); // swap kardo
                        swapped = true; // changing flag
                    }
                    else{
                        // cant able to swap as set bits are not same
                        return false;
                    }
                }
            }

            if(swapped == false){ // nos wapping is done hence arr is already sorted
                break;
            }

        }
        return true;
    }
};

// Segment Sort Check
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        //Current Segment
        int numOfSetBits = __builtin_popcount(nums[0]);
        int maxOfSegment = nums[0];
        int minOfSegment = nums[0];

        int maxOfPrevSegment = INT_MIN;

        for (int i = 1; i < nums.size(); i++) {
            if (__builtin_popcount(nums[i]) == numOfSetBits) { //they belong to same segment
                maxOfSegment = max(maxOfSegment, nums[i]); //find max of current segment
                minOfSegment = min(minOfSegment, nums[i]); //find min of current segment
            } else {  // Element belongs to a new segment
                
                if (minOfSegment < maxOfPrevSegment) { //ye bataya hai maine video me
                    return false;
                }

                // Update the previous segment's max
                maxOfPrevSegment = maxOfSegment;

                // new segment started now
                maxOfSegment = nums[i];
                minOfSegment = nums[i];
                numOfSetBits = __builtin_popcount(nums[i]);
            }
        }
        // Final check for proper segment arrangement
        if (minOfSegment < maxOfPrevSegment) {
            return false;
        }
        return true;
    }
};
