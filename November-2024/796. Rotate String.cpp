// Bruteforce Rotate and check
// O(n^2)
// O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        if(m!=n){
            return false;
        }

        // run loop till m
        for(int i = 0; i<=m ; i++){
            // rotate function {start, which will become new start, end}
            rotate(s.begin(), s.begin() + 1, s.end());

            if(s==goal){
                return true;
            }
        }
        return false;
    }
};

// Concat and find
// O(n)
// O(1)

class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        if(m!=n){
            return false;
        }

        // if we concatinate or add the string to itself it will have all its permutations of that particular string
        if((s+s).find(goal) != string::npos){
            return true;
        }

        return false;
    }
};
