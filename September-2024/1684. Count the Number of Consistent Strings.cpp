// Approach 1 -> Using Hash Set
//T.C : O(m + n*k)
//S.C : O(m)

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;

        int count = 0;

        for(auto c : allowed){
            st.insert(c);
        }

        for(auto chars : words){
            bool flag = true;
            for(int i = 0 ; i< chars.length(); i++){
                if(st.find(chars[i]) == st.end()){
                    flag = false;
                    break;
                }
            }
            if(flag){
                count++;
            }
        }

        return count;
    }
};

// Approach 2 -> Using Bit Mask
//T.C : O(m + n*k)
//S.C : O(1)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // creation of mask
        int mask = 0;

        for(auto ch:allowed){
            mask |= (1 << (ch - 'a'));
        }

        int count = 0;

        for(auto word : words){
            bool flag = true;

            for(auto ch : word){
                if(((mask >> (ch - 'a')) & 1) == 0){
                    flag = false;
                    break;
                }
            }

            if(flag){
                count++;
            }
        }

        return count;
    }
};
