// Bruteforce 
class Solution {
public:
    int minChanges(string s) {
        int n = s.length();

        char ch = s[0];
        int count = 0;

        int changes = 0;

        for(int i = 0; i< n ; i++){
            if(s[i] == ch){
                count++;
                continue;
            }

            // curr ch barabar nahi hai
            
            // check for prev count even or odd
            if(count % 2 == 0){
                count = 1; // start new streak
            }
            else{
                changes += 1;
                count = 0; // reset count;
            }

            // we have to update curr ch
            ch = s[i]; // update to new char
        }
        return changes;
    }
};

// Better
class Solution {
public:
    int minChanges(string s) {
        int n = s.length();

        int changes = 0;
        
        for(int i = 0; i<n ; i += 2){
            // we check window of 2
            if(s[i] != s[i+1]){
                changes++;
            }
        }

        return changes;
    }
};
