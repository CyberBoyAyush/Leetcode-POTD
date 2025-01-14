class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int>res(n);

        unordered_map<int,int> mpp;

        int count = 0;

        for(int i = 0; i<n ; i++){
            // storing and inc freq
            mpp[A[i]]++;

            if(mpp[A[i]] == 2){
                count+=1;
            }

            mpp[B[i]]++;

            if(mpp[B[i]] == 2){
                count+=1;
            }

            res[i] = count;
        }
        return res;
    }
};
