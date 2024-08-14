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


// Approach 2 -> Using STL (nth element) [only works in C++]
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


// Approach 3 -> Sliding Window + Binary Search (Most Optimal)
// TC - O(Nlogn+Nlogd)
// SC - O(1)

class Solution {
public:
    int slidingWindow(vector<int> &nums, int dist){
        int i = 0;
        int j = 1;

        int n = nums.size();
        int pairCount = 0;
        
        while(j < n){
            while(nums[j] - nums[i] > dist){
                i++;
            }
            pairCount += j-i;
            j++;
        }

        return pairCount;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        // sort the array
        sort(nums.begin(),nums.end());

        // Apply Binary Search to find distance 
        int l = 0;
        int h = nums[n-1] - nums[0]; // diff or highest and lowest

        int result = 0;

        while(l <= h){
            int mid = (l + h) / 2;

            int countPairs = slidingWindow(nums,mid);

            if(countPairs < k){
                l = mid +1;
            }
            else{
                result = mid;
                h = mid - 1; // go check smallest if there is any smaller than that
            }
        }

        return result;
    }
};
