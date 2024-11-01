class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();

        string ans = "";
        ans.push_back(s[0]); // pushing 1st char in the ans string
        int freq = 1; // holds the freq of current char

        for(int i = 1; i<n ; i++){
            if(s[i] == ans.back()){
                ans.push_back(s[i]);
                freq++;

                if(freq > 2){
                    ans.pop_back();
                    freq--;
                }
            }
            else{
                ans.push_back(s[i]);
                freq = 1;
            }
        }

        return ans;
    }
};
