class Solution {
public:
    int bfs(unordered_map<int, vector<int>> &adj, int n){
        // queue for bfs
        queue<int> q;
        q.push(0); // src node

        vector<bool> vis(n,0); // track visited nodes
        vis[0] = 1;

        int level = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();

                if(node==n-1){
                    // reached final node
                    return level;
                }

                for(auto& neig : adj[node]){
                    if(!vis[neig]){
                        vis[neig] = 1;
                        q.push(neig);
                    }
                }
            }
            level++;
        }

        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // CREATING ADJ LIST
        unordered_map<int, vector<int>> adj;

        // mapping
        for(int i = 0; i<=n-2; i++){
            adj[i].push_back(i+1); // 0->1->2->3->4->5
        }

        vector<int> res;
        // processing every query
        for(auto &query : queries){
            int u = query[0];
            int v = query[1];

            adj[u].push_back(v);

            int d = bfs(adj,n);

            res.push_back(d);
        }

        return res;
    }
};
