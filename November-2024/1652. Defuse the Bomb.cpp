// Bruteforce
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> res(n,0);

        for(int i = 0; i< n; i++){
            if(k < 0){
                // negative K
                for(int j = i - abs(k) ; j<i; j++){
                    res[i] += code[(j+n)%n]; // circular hai
                }
            }
            else{
                // pos k
                for(int j = i+1; j<=i+k; j++){
                    res[i] += code[j % n];
                }
            }
        }
        return res;
    }
};

// Sliding Window
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> res(n,0);

        int i = -1; int j = -1;

        if(k>0){
            i = 1;
            j = k;
        }
        else{
            i = n - abs(k);
            j = n-1;
        }

        int windowSum = 0;

        for(int p = i; p<=j ; p++){
            windowSum += code[p];
        }

        for(int k = 0; k<n ; k++){
            res[k] = windowSum;

            windowSum -= code[i%n];
            i++;

            windowSum += code[(j+1) % n];
            j++;
        }

        return res;
    }
};
