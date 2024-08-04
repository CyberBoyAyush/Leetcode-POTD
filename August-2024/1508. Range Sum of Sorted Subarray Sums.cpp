// Appraoch 1 -> Bruteforce 
//TC - O(n^2 * logn) SC - O(n)

class Solution {
public:
    int M = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> temp;

        // 1.) Finding the sum of all sub arrays
        for(int i = 0; i<n ; i++){
            int sum = 0;
            for(int j = i ; j<n ; j++){
                sum += nums[j];
                temp.push_back(sum);
            }
        }

        // 2.) sorting the arr
        sort(temp.begin(),temp.end());
        int result = 0;

        // 3.) sending desired result
        for(int i = left-1 ; i <= right-1 ; i++){
             result = (result + temp[i]) % M;
        }

        return result;

    }
};


// Approach 2 -> Using Heap
//T.C : O(n^2 *n logn)
//S.C : O(n)
class Solution {
public:
    typedef pair<int,int> P; // {subarray sum, end index of this subarray sum}
    int M = 1e9 + 7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<P, vector<P> , greater<P>> pq; // Min heap

        // pushing the smallest subarray possible in minheap
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        int result = 0;

        for(int count = 1; count <= right; count++){
            auto p = pq.top();
            pq.pop();

            // Retrieval of value from pair
            int sum = p.first;
            int idx = p.second;

            if(count >= left){
                result = (result + sum) % M;
            }

            int new_idx = idx + 1;
            if(new_idx < n){
                pq.push({sum + nums[new_idx], new_idx});
            }
        }

        return result;
    }
};
