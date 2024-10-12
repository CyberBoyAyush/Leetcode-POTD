// Bruteforce - (TLE)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int ramp = 0;
        for(int i = 0; i<n ; i++){
            for(int j = i + 1; j<n ; j++){
                if(nums[j] >= nums[i]){
                    ramp = max(ramp, j - i);
                }
            }
        }

        return ramp;
    }
};

// Better (TLE)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        int ramp = 0;

        for(int i = 0; i < n; i++) {
            for(int j = n-1; j > i; j--) {
                if(nums[i] <= nums[j]) {
                    ramp = max(ramp, j-i);
                    break;
                }
            }
        }
        return ramp;
    }
};

// Two Pointer - Optimal
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        vector<int> rightMax(n);
        rightMax[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], nums[i]);
        }

        int ramp = 0;
        int i = 0;
        int j = 0;

        while(j<n){
            while(i<j && nums[i] > rightMax[j]){
                // we shift i
                i++;
            }

            ramp = max(ramp,j-i);
            j++;
        }
        return ramp;
    }
};

// Monotonic Stack - Most Optimal
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for(int i = 0; i<n ; i++){
            if(st.empty() || nums[st.top()] > nums[i]){
                // we push
                st.push(i); // as we need decreasing data structure
            }
        }

        int ramp = 0;

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                ramp = max(ramp, i - st.top());
                st.pop();
            }

            if(st.empty()){
                break;
            }
        }

        return ramp;
    }
};
