// 209. Minimum Size Subarray Sum -> Pre requisite question
// https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int len = INT_MAX;  // as we need minimum

        int sum = 0;

        int i = 0;
        int j = 0;

        while(j<n){
            sum += nums[j];

            while(sum >= target){
                len = min(len , j - i + 1);
                sum -= nums[i]; // shirnk the window for better ans
                i++;
            }
            j++;
        }

        return len == INT_MAX ? 0 : len;
    }
};

// Now the solution using monotonic deque and sliding window (using deq as we need to avoid -ve numbers)
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq; // monotonic deque (increasing)

        vector<long long> cumSum(n, 0); // stores the cummulativeSum

        int result = INT_MAX; // as we need to minimize it

        int j = 0;

        while(j<n){
            // calcuating cumSum
            if(j == 0){
                // first el
                cumSum[j] = nums[j];
            }
            else{
                cumSum[j] = cumSum[j-1] + nums[j];
            }

            // while calculating if cumSum is greater than k it will be our window
            if(cumSum[j] >= k){
                result = min(result, j + 1);
            }

            // need to shrink the window or not
            while(!deq.empty() && cumSum[j] - cumSum[deq.front()] >= k){
                // we can shrink the window
                result = min(result, j - deq.front());
                deq.pop_front(); // pop front
            }

            // pop to maintain the monotnonic nature
            while(!deq.empty() && cumSum[j] <= cumSum[deq.back()]){
                deq.pop_back();
            }

            deq.push_back(j); // pushing j in deq
            j++;
        }

        return result == INT_MAX ? -1:result;
    }
};
