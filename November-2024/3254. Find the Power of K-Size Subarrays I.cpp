// Approach 1 -> Sliding Window
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> res(n - k + 1, -1); //final ans vector

        int count = 1;

        // processing the first window
        for(int i = 1; i<k ; i++){
            if(nums[i] == nums[i-1]+1){
                count++;
            }
            else{
                count = 1;
            }
        }

        if(count == k){
            res[0] = nums[k-1]; // k -1 has the largest element
        }

        int i = 1; 

        int j = k;

        while(j<n){
            if(nums[j] == nums[j-1] + 1){
                // consecutive
                count++;
            }
            else{
                count = 1;
            }

            if(count >= k){
                res[i] = nums[j]; // nums[j] hold the largest elemt and i hold which index is it (window)
            }

            i++;
            j++;
        }

        return res;

    }
};

// Appraoch 2 -> Monotonic Stack
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq; // monotonic deque

        vector<int>res; // final ans

        for(int j = 0; j<n ; j++){
            if(deq.size() == k){
                deq.pop_front(); // to decrease size of deq
            }

            if(!deq.empty() && deq.back() != nums[j] - 1){
                // deq is not consecutive
                deq.clear();
            }

            deq.push_back(nums[j]); // deq is consecutive

            if(j >= k-1){
                if(deq.size() == k){
                    res.push_back(deq.back()); // last element
                }
                else{
                    res.push_back(-1); // pushing -1 
                }
            }
        }
        return res;
    }
};
