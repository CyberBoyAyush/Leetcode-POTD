// Appraoch 1 -> finding prefix and comparing them using set
// TC - O(N + M)
// SC - O(N)
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        for(auto val : arr1){
            // pushing values of arr1 into set (prefixes)
            while(!st.count(val) && val > 0){
                st.insert(val);
                val = val / 10; // reducing for anothe prefix
            }
        } 

        int result = 0; // Longest common prefix

        for(auto num : arr2){
            while(!st.count(num) && num > 0){
                // finding prefix in arr 2 from set
                num = num / 10;
            }
            if(num > 0)
                result = max(result, (int)(log10(num) + 1));
        }

        return result;
    }
};
