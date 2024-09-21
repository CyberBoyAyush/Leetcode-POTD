// Appraoch 1 -> Finding all sub str and then comparing it and adding it to original string
// TC - O(n^2)
// SC - O(n)

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());

        for(int i = 0 ; i< s.length(); i++){
            if(s.substr(0,s.length() - i) == rev.substr(i)){
                // if both are equal
                return rev.substr(0,i) + s;
            }
        }

        return rev + s;
    }
};

// Appraoch 2 -> Same as prev appraoch but using memcmp function which do not create substr but rather comapre it from the memory
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());

        for(int i = 0 ; i< s.length(); i++){
            if(memcmp(s.c_str() , rev.c_str() + i, s.length() - i) == 0){
                // if both are equal 
                return rev.substr(0,i) + s;
            }
        }

        return rev + s;
    }
};


// Appraoch 3 -> KMP Algo
class Solution {
public:
    void computeLPS(string pat, vector<int> &LPS, int M){
        int len = 0;
        LPS[0] = 0;
        
        int i = 1;
        
        while(i<M){
            if(pat[i] == pat[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            
            else{
                if(len!=0){
                    len = LPS[len-1];
                }
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());

        string temp = s + "-" + rev;

        vector<int> LPS(temp.length(),0);

        computeLPS(temp,LPS,temp.length());

        int longestLPS = LPS[temp.length() - 1];

        string culprit = rev.substr(0,s.length() - longestLPS);

        return culprit + s;
    }
};
