class Solution {
public:
    #define P pair<int, pair<int,int>>
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // resultant vector will be 2d as we have a matrix
        vector<vector<int>> res(n, vector<int>(m,INT_MAX));

        res[0][0] = 0; // dist from 0 to 0 will be 0 only

        priority_queue<P, vector<P> , greater<P>> pq; // for dikstra

        pq.push({0,{0,0}}); // {wt, {i,j} };

        while(!pq.empty()){
            auto curr = pq.top();

            pq.pop();

            int d = curr.first;
            int i = curr.second.first; // row
            int j = curr.second.second; // col

            for(auto &dir:directions){
                // traverse in all 4 ways
                int x = i+dir[0];
                int y = j+dir[1];

                // check limits
                if(x < 0 || x>=n || y<0 || y>=m){
                    continue; // ksip this iterations
                }

                int wt = (grid[x][y]) == 1 ? 1:0; // it there is obstacle wt will be 1 else 0
                
                // classic dikstra
                if(d + wt < res[x][y]){
                    // change it
                    res[x][y] = d + wt;

                    // push in pq
                    pq.push({d + wt, {x,y}});
                }
            }
        }
        return res[n-1][m-1];
    }
};
