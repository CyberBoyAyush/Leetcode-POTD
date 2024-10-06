// Approach 1 -> Sorting and Find
// TC - O(nlogn + m-n)
// SC - O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        // base edge case
        if(n > m){
            return false;
        }

        // sort string s1
        sort(s1.begin(),s1.end());

        for(int i = 0; i<=m-n ; i++){
            string substring = s2.substr(i,n);

            sort(begin(substring),end(substring));

            // now we check
            if(s1 == substring){
                return true;
            }
        }

        return false;
    }
};


// Approach 2 -> Using Sliding Window and Freq Table
// TC - O(m + n)
// SC - O(26 + 26)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        // base edge case
        if(n > m){
            return false;
        }

        // freq array for s1
        vector<int> s1_freq(26,0);
        // freq arr for s1
        vector<int> s2_freq(26,0);

        // filling the s1 freq arr
        for(auto ch : s1){
            s1_freq[ch - 'a']++;
        }

        int i = 0;
        int j = 0;

        while(j < m){
            s2_freq[s2[j] - 'a']++;
            if(j - i + 1 > n){
                // keeping in limit shring it
                s2_freq[(s2[i] - 'a')]--;
                i++;
            }

            // comparing with s1 freq
            if(s1_freq == s2_freq){
                return true;
            }

            j++;
        }
        return false;
    }
};
