// Approach 1 -> DFS
//T.C : O(m*n)
//S.C : O(1) //I am not considering the space taken by System Recursion stack
class Solution {
public:
    bool DFS(int i, int j , vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(i < 0 || i >= grid2.size() || j < 0 ||j >= grid2[0].size()){
            return true;
        }

        if(grid2[i][j] != 1)    return true; // we only need land

        grid2[i][j] = -1; // marking it visited

        bool result = (grid1[i][j] == 1); // store if grid1 at same place has 1 or not

        
        result = result & DFS(i+1,j,grid1,grid2); // down
        result = result & DFS(i-1,j,grid1,grid2); // up
        result = result & DFS(i,j-1,grid1,grid2); // left
        result = result & DFS(i,j+1,grid1,grid2); // right

        return result;

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int subIslands = 0; // counts the number of subislands we found

        int m = grid2.size(); // row
        int n = grid2[0].size(); // cols


        for(int i = 0 ; i<m ; i++){
            for(int j = 0; j<n ; j++){
                if(grid2[i][j] == 1 && DFS(i,j,grid1,grid2)){
                    subIslands++; // found a subisland
                }
            }
        }

        return subIslands;

    }
};

// Approach 2 -> BFS
//T.C : O(m*n)
//S.C : O(m*n) //Queue
class Solution {
public:
vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //down, up, right , left
bool BFS(int i, int j , vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int m = grid2.size();
        int n = grid2[0].size();

        bool result = true; // initially we mark it as true

        queue<pair<int,int>> q; //{i,j}

        q.push({i,j});

        grid2[i][j] = -1; // marking it visited

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            if(grid1[x][y] != 1)    result = false; // mark it false

            // going in neighbours
            for(auto dir : directions){
                int new_x = x + dir[0]; 
                int new_y = y + dir[1];

                // chekc if newx and newy are in limits
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && 
                grid2[new_x][new_y] == 1){
                   grid2[new_x][new_y] = -1; // makring it visited
                   q.push({new_x,new_y}); 
                }
            }
        }
        
        return result;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int subIslands = 0; // counts the number of subislands we found

        int m = grid2.size(); // row
        int n = grid2[0].size(); // cols


        for(int i = 0 ; i<m ; i++){
            for(int j = 0; j<n ; j++){
                if(grid2[i][j] == 1 && BFS(i,j,grid1,grid2)){
                    subIslands++; // found a subisland
                }
            }
        }

        return subIslands;

    }
};
