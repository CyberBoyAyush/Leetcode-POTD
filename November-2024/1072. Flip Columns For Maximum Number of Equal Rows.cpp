// Bruteforce: Comparing similar and inverted rows
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxCnt = 0;

        for(auto &currRow : matrix){
            // inverted row
            vector<int>inverted(n);

            for(int col = 0 ; col<n ; col++){
                inverted[col] = currRow[col] == 0 ? 1:0; // flip 
            }

            int count = 0;

            for(auto & row:matrix){
                if(row == currRow || row == inverted){ // vector is getting compared
                    count++; 
                }
            }

            maxCnt = max(maxCnt,count);
        }

        return maxCnt;
    }
};

// Hashmap and Comparing
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mpp;

        for(auto &row : matrix){
            string rowNature = "";

            int firstVal = row[0];
            for(int col = 0; col<matrix[0].size(); col++){
                rowNature += (row[col] == firstVal) ? "S":"B";
            }

            mpp[rowNature]++; // pushing row nature in map
        }

        int maxCnt = 0;

        for(auto & it:mpp){
            maxCnt = max(maxCnt, it.second);
        }

        return maxCnt;
    }
};
