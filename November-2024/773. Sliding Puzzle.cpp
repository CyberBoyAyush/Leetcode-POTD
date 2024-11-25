// TC - O(6!)
// SC - O(6!)
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = ""; // string which contains the matrix el in start of operations in string

        for(int i = 0;i<2; i++){
            for(int j = 0; j<3; j++){
                start += to_string(board[i][j]);
            }
        }

        string target = "123450"; // this is the final string target that we have to archieve after applying bfs on matrix as final

        queue<string> que; // for bfs
        que.push(start); // pushing starting condt of matrix in queue for BFS
        unordered_map<int, vector<int>> mpp; // store at what pos of 0 in string it can swap with which pos acc to matrix in string

        mpp[0] = {1,3};
        mpp[1] = {0,2,4};
        mpp[2] = {1,5};
        mpp[3] = {0,4};
        mpp[4] = {1,3,5};
        mpp[5] = {2,4};

        unordered_set<string> visited; // check if we have prev visited it or not
        visited.insert(start); // amrking start as visited

        int moves = 0; // final ans

        while(!que.empty()){
            int n = que.size();
            while(n--){
                string currState = que.front();
                que.pop();

                if(currState == target){
                    return moves;
                }

                // finding index of 0 for further operations
                int idxofZero = currState.find('0');

                // now checking  on which indices we can swap it from mpp map
                for(int &swapIdx : mpp[idxofZero]){
                    // here this loop traverse to every pos out idx of zero el can swap with
                    string newState = currState;

                    // swap it
                    swap(newState[swapIdx], newState[idxofZero]);

                    if(visited.find(newState) == visited.end()){
                        // we havent seen it before
                        que.push(newState);
                        visited.insert(newState);
                    }
                }  
            }
            moves++; // as level is increased
        }
        return -1; // as it looks like we never found the target

    }
};
