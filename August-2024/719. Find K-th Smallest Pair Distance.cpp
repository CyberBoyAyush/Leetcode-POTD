// Approach 1 -> using mathematics and observation
// 1 -> we find the freq of each distance possible for every paid
// 2 -> we return that while calcualtion with k

// TC - O(N^2)
// SC - O(M) // M is the maximum element in nums
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
      int n = nums.size();

      int maxEl = *max_element(nums.begin(),nums.end());
      vector<int> vec(maxEl + 1, 0); // stores count freq

      for(int i = 0; i<n ; i++){
        for(int j = i+1; j<n ; j++){
            int dist = abs(nums[i] - nums[j]);
            vec[dist] ++;
        }
      }

      for(int d = 0 ; d<maxEl ; d++){
        k -= vec[d];
        if(k <= 0){
            return d;
        }
      }  
      return -1;
    }
};


// Appraoch 2 -> Using STL (nth element) [only works in c++]
// TC - O(n^2)
// SC - O(n * (n-1)/2)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> vec(n * (n-1)/2);

        int idx = 0; // for vec

        for(int i = 0; i<n ; i++){
            for(int j = i+1; j<n ; j++){
                int d = abs(nums[i] - nums[j]);
                vec[idx] = d;
                idx++;
            }
        }

        // nth element partial sorting
        nth_element(begin(vec) , begin(vec) + k-1 , end(vec));
        return vec[k-1];
    }
};
