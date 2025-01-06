// Good Approach
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<char> letters;

        // pushing all letters in this set for further processing
        for(int i = 0;i<n ; i++){
            letters.insert(s[i]);
        }

        // futher prcessing to find palindrome
        int ans = 0;

        for(char letter : letters){
            int left_idx = -1;
            int right_idx = -1;

            // finding index of letter right most na dleft most
            for(int i = 0; i<n ; i++){
                if(s[i] == letter){
                    if(left_idx == -1){
                        left_idx = i;
                    }

                    right_idx = i; // continuous as we get it again 
                }
            }

            // not putting between chars in set for result calci
            unordered_set<char> st;

            for(int middle = left_idx+1; middle < right_idx ; middle++){
                st.insert(s[middle]);
            }

            ans += st.size();
        }
        return ans;
    }
};

// Better Way -> Precomputing location
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<pair<int, int>> indices(26, {-1, -1});
        
        for(int i = 0; i<n; i++) {
            char ch = s[i];
            int idx = ch-'a';
            
            if(indices[idx].first == -1) {
                indices[idx].first = i;
            }
            
            indices[idx].second = i;
        }
        
        
        int result = 0;
        for(int i = 0; i<26; i++) {
            if(indices[i] == make_pair(-1, -1)) {
                continue;
            }
            
            unordered_set<char> st;
            for(int middle = indices[i].first+1; middle <= indices[i].second-1; middle++) {
                
                st.insert(s[middle]);
                
            }
            
            result += st.size();
        }
        
        return result;
    }
};
