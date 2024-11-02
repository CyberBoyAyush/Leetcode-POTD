// Approach 1 -> Using Map
// TC - O(nlogn) -> sorting
// SC - O(n)
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Map for storing the data and streak value
        unordered_map<int,int> mpp;

        // sorting the nums
        sort(nums.begin(),nums.end());

        int maxStreak = 0; // stores the mas streak

        for(int & num:nums){
            // check if the number is perfect square
            int root = (int)sqrt(num);

            if(root * root == num && mpp.find(root) != mpp.end()){
                // it is perfect square
                mpp[num] = mpp[root] + 1;
            }
            else{
                mpp[num] = 1;
            }

            // updating maxStreak
            maxStreak = max(maxStreak, mpp[num]);
        }

        return maxStreak < 2 ? -1 : maxStreak;
    }
};

// Approach 2 -> Using set to store and find its square in it

// TC - O(n) + O(5) -> beacuse of Constraints 10^5
// SC - O(n)

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // unordered set
        unordered_set<int> st(begin(nums), end(nums));

        int maxStreak = 0; // holds max streak

        for(int & num : nums){
            int streak = 0;
            long long curr = num;
            while(st.find(curr) != st.end()){
                // we found it
                streak++;

                // update curr to its square to find it further
                // we have Constraints of 10^5 so we chekc it
                if(curr*curr > 1e5) break; 
                // it will make sure that the shile loops runs atmax of 5 times which will make this loop constant

                curr *= curr;
            }

            maxStreak = max(maxStreak, streak);
        }
        return maxStreak < 2 ? -1 : maxStreak;
    }
};
