// Preprocessing and Check
// TC - O(m*n) SC - O(m + n)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // vectors for pre processing
        vector<int> colCnt(n,0);
        vector<int> rowCnt(m,0);

        // preprocessing
        for(int i = 0; i<m ; i++){
            for(int j = 0; j<n ;j++){
                if(grid[i][j] == 1){
                    // server is there
                    rowCnt[i]+=1;
                    colCnt[j]+=1;
                }
            }
        }

        int resServer = 0;

        for(int i = 0; i<m ; i++){
            for(int j = 0; j<n ;j++){
                if(grid[i][j] == 1 && ((rowCnt[i] > 1) || (colCnt[j]>1))){
                    resServer++;
                }
            }
        }

        return resServer;
    }
};
