class Solution {
public:
    #define P pair<int, pair<int,int>> 
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}}; // 4 allowed directions
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // edge case -> if nearest el from start is greater than 1 then we cant traverse
        if(grid[0][1] > 1 && grid[1][0] > 1){
            return -1;
        }

        vector<vector<int>> res(n, vector<int>(m, INT_MAX)); // res matrix fro dijkstra
        res[0][0] = 0;

        // pq for dijkstra implementation
        priority_queue<P, vector<P>, greater<P>> pq; // min heap
        pq.push({0, {0,0}}); // {time, {row,col}}

        vector<vector<bool>> vis(n, vector<bool>(m, 0)); // tracks if visited or not

        while(!pq.empty()){
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop(); // removing el from pq

            // check if we have reached the final dest
            if(row == n-1 && col == m-1){
                return time; // we have reached the final dest.
            }

            // chekc visited
            if(vis[row][col] == true){
                continue;
            }

            // makring vis
            vis[row][col] = true;

            // go in every dir
            for(auto &dir:directions){
                int x = row + dir[0];
                int y = col + dir[1];

                // check safe
                if(x<0 || x>=n || y<0 || y>=m){
                    continue; // not safe
                }

                // cases to go
                if(grid[x][y] <= time+1){
                    // we can go
                    pq.push({time+1, {x,y}}); // pushing it in pq
                    res[x][y] = time + 1;
                }

                else if((grid[x][y] - time) % 2 == 0){
                    // even time diff -> we need grid[x][y] + 1 time to reach it here as we need to use and increase time before reaching it
                    int valOfTime = grid[x][y] + 1;
                    pq.push({valOfTime, {x,y}});
                    res[x][y] = valOfTime;
                }
                else{
                    // time diff is odd -> we need same time as grid[x][y]
                    int valOfTime = grid[x][y];
                    pq.push({valOfTime, {x,y}});
                    res[x][y] = valOfTime;
                }
            }
        }

        return -1;
    }
};
