// Recursion TLE
class Solution {
public:
    int res = INT_MAX; // as we need minimum minutes
    void solve(int i, int j, int k, string &s, vector<int> freq, int minutes){
        // check if res is k or not
        if(freq[0] >= k && freq[1] >= k && freq[2] >= k){
            // we have deleted needed
            res = min(res, minutes);
            return;
        }

        // base case
        if(i>j){
            return;
        }

        // del from left -> i
        vector<int> delLeft = freq;
        delLeft[s[i] - 'a'] += 1;
        solve(i+1, j, k,s,delLeft, minutes+1); // recursive call with i+1 and Minutes + 1


        // del from left -> i
        vector<int> delRight = freq;
        delRight[s[j] - 'a'] += 1;
        solve(i, j-1, k,s,delRight, minutes+1); // recursive call with j-1 and Minutes + 1


    }
    int takeCharacters(string s, int k) {
        vector<int> freq(3,0); // {a,b,c}
        int i = 0;
        int j = s.length()-1;
        int minutes = 0;

        solve(i,j,k,s,freq,minutes);

        return res == INT_MAX ? -1 : res;
    }
};

// SLiding Window
class Solution {
public:
    //Khandani sliding window
    int takeCharacters(string s, int k) {
        int n = s.length();

        int count_a = 0; //delete
        int count_b = 0; //delete
        int count_c = 0; //delete
        for(char &ch : s) {
            if(ch == 'a')
                count_a++;
            else if(ch == 'b')
                count_b++;
            else
                count_c++;
        }

        if(count_a < k || count_b < k || count_c < k) {
            return -1; //not possible to delete k characters
        }

        int i = 0;
        int j = 0; 
        int notDeletedWindowSize = 0;

        while(j < n) {
            if(s[j] == 'a') {
                count_a--;
            } else if(s[j] == 'b') {
                count_b--;
            } else if(s[j] == 'c') {
                count_c--;
            }

            //if deletion count of any character becomes less than k, then shrink the window and bring them back
            while(i <= j && (count_a < k || count_b < k || count_c < k)) {
                //ith pointer move to left
                if(s[i] == 'a') {
                    count_a++;
                } else if(s[i] == 'b') {
                    count_b++;
                } else {
                    count_c++;
                }
                i++;
            }

            notDeletedWindowSize = max(notDeletedWindowSize, j-i+1);
            j++;
        }

        return n - notDeletedWindowSize; //minutes

    }
};
