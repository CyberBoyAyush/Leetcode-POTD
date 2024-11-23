// Simulation + Brute
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        // res vector
        vector<vector<char>> res(n, vector<char>(m));

        // step 1 : find traspose of matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = box[j][i];
            }
        }

        // step 2 : reverse every row to archeive 90 degree
        for (auto& row : res) {
            reverse(row.begin(), row.end());
        }

        // Step 3: apply the gravity
        for (int j = 0; j < m; j++) { // processing col
            for(int i = n-1; i>=0; i--){ // processing row in reverse order of that col
                if(res[i][j] == '.'){
                    int stoneRow = -1;

                    for(int k = i-1; k>=0 ; k--){
                        // if we found a stationary obstacle
                        if(res[k][j] == '*'){
                            break; // stone cant be here
                        }
                        else if(res[k][j] == '#'){
                            stoneRow = k; // storing k in stonerow
                            break;
                        }
                    }

                    if(stoneRow != -1){
                        // putting stone after gravity to i j
                        res[i][j] = '#';

                        // removing stone from stoneRow putting empty spaces there
                        res[stoneRow][j] = '.';
                    }
                }
            }
        }

        return res;
    }
};

// Same as prev + Some optimiation by storing empty spaces and moving rock there without k loop
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        // res vector
        vector<vector<char>> res(n, vector<char>(m));

        // step 1 : find traspose of matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = box[j][i];
            }
        }

        // step 2 : reverse every row to archeive 90 degree
        for (auto& row : res) {
            reverse(row.begin(), row.end());
        }

        // Step 3: apply the gravity
        for(int j = 0; j<m ; j++){
            int spaceBottom = n-1; // last place where we saw the space (n-1 bcz we now n-1 is bottom of box)
            for(int i = n-1; i>=0; i--){
                if(res[i][j] == '*'){
                    // edge case of obstacle
                    spaceBottom = i - 1;
                    continue;
                }
                if(res[i][j] == '#'){
                    res[i][j] = '.'; // as rock moves so we make it empty
                    res[spaceBottom][j] = '#'; // rock is moved (gravity applied)
                    spaceBottom--; // as prev space is already occupied
                }
            }
        }

        return res;
    }
};
