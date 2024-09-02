// Approach 1 -> Simulation (TLE)

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        while(true){
            for(int i = 0 ; i< chalk.size(); i++){
                if(k < chalk[i]){
                    return i;
                }
                k -= chalk[i];
            }
        }
    }
};

// Approach 2 -> Better Method using MOD
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        long long totalChalkSum = 0; // sum of chalk in one iteration

        for(int i = 0; i< n ; i++){
            totalChalkSum += chalk[i];
        }

        int remChalkSum = k % totalChalkSum;

        for(int i = 0 ; i< n ; i++){
            if(remChalkSum < chalk[i]){
                return i;
            }

            remChalkSum -= chalk[i];
        }

        return -1;
    }
};
