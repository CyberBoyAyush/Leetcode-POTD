class Solution {
public:
    int minimumPushes(string word) {
        // Taking map or a vector for storing the frequency
        vector<int> mpp(26,0);

        // calculating the frequency
        for(char &ch:word){
            mpp[ch - 'a']++;
        }

        // sorting it accoirding to descending order of frequency
        sort(mpp.begin(),mpp.end(),greater<int>());

        int result = 0;

        for(int i = 0 ; i<26 ; i++){
            int freq = mpp[i];
            int pressNeeded = i/8 + 1;

            result += freq * pressNeeded;
        }

        return result;
    }
};
