// Approach 1 -> Using Map and store states (Same as appraoch 1 )
// TC - O(N)
// SC - O(N)

class Solution {
public:
    int findTheLongestSubstring(string s) {
        // map for storing the state and which index it was on last time
        unordered_map<string,int> mpp;

        // vetcor which stores vowel counts
        vector<int> state(5,0); // a e i o u

        string currState = "00000";

        mpp[currState] = -1;

        int result = 0; // stores the length

        for(int i = 0; i<s.length(); i++){
            if(s[i] == 'a'){
                state[0] = (state[0] + 1) % 2;
            }
            else if(s[i] == 'e'){
                state[1] = (state[1] + 1) % 2;
            }
            else if(s[i] == 'i'){
                state[2] = (state[2] + 1) % 2;
            }
            else if(s[i] == 'o'){
                state[3] = (state[3] + 1) % 2;
            }
            else if(s[i] == 'u'){
                state[4] = (state[4] + 1) % 2;
            }

            // now generating curr state
            currState = "";

            for(int j = 0 ; j<5; j++){
                currState += to_string(state[j]);
            }

            // comparing it to map
            if(mpp.find(currState) != mpp.end()){
                result = max(result, i - mpp[currState]);
            }
            else{
                // update it in map
                mpp[currState] = i;
            }
        }
        return result;
    }
};

// Approach 2 -> Using XOR for state
// TC - O(N)
// SC - O(N)

class Solution {
public:
    int findTheLongestSubstring(string s) {
        // map for storing the state and which index it was on last time
        unordered_map<string,int> mpp;

        // vetcor which stores vowel counts
        vector<int> state(5,0); // a e i o u

        string currState = "00000";

        mpp[currState] = -1;

        int result = 0; // stores the length

        for(int i = 0; i<s.length(); i++){
            if(s[i] == 'a'){
                state[0] = (state[0] ^ 1);
            }
            else if(s[i] == 'e'){
                state[1] = (state[1] ^ 1);
            }
            else if(s[i] == 'i'){
                state[2] = (state[2] ^ 1);
            }
            else if(s[i] == 'o'){
                state[3] = (state[3] ^ 1);
            }
            else if(s[i] == 'u'){
                state[4] = (state[4] ^ 1);
            }

            // now generating curr state
            currState = "";

            for(int j = 0 ; j<5; j++){
                currState += to_string(state[j]);
            }

            // comparing it to map
            if(mpp.find(currState) != mpp.end()){
                result = max(result, i - mpp[currState]);
            }
            else{
                // update it in map
                mpp[currState] = i;
            }
        }
        return result;
    }
};

// Approach 3 -> Using Mask And XOR Property
// O(N)
// O(1)

class Solution {
public:
    int findTheLongestSubstring(string s) {
        // map for storing the state and which index it was on last time
        unordered_map<int,int> mpp;

        int mask = 0; // 00000

        mpp[mask] = -1;

        int result = 0; // stores the length

        for(int i = 0; i<s.length(); i++){
            if(s[i] == 'a'){
                mask = (mask ^ (1<<0));
            }
            else if(s[i] == 'e'){
                mask = (mask ^ (1<<1));
            }
            else if(s[i] == 'i'){
                mask = (mask ^ (1<<2));
            }
            else if(s[i] == 'o'){
                mask = (mask ^ (1<<3));
            }
            else if(s[i] == 'u'){
                mask = (mask ^ (1<<4));
            }

            // comparing it to map
            if(mpp.find(mask) != mpp.end()){
                result = max(result, i - mpp[mask]);
            }
            else{
                // update it in map
                mpp[mask] = i;
            }
        }
        return result;
    }
};
