class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int m = spaces.size();
        string ans = "";
        int j = 0; // for traversal in spaces vector

        for(int i = 0; i<n ; i++){
            if(j<m && i == spaces[j]){
                ans += " ";
                j++;
            }

            ans += s[i];
        }

        return ans;
    }
};
