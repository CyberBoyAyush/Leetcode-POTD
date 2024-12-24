class Solution {
public:
    unordered_map<int,vector<int>> adjBuild(vector<vector<int>>& edges){
        unordered_map<int,vector<int>> adj;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    pair<int,int> BFS(unordered_map<int,vector<int>> &adj, int src){
        queue<int> q;
        q.push(src);

        unordered_map<int, bool> vis;
        vis[src] = 1;

        int dist = 0;
        int farthestNode = src; // initial it will be src only

        while(!q.empty()){
            int n = q.size();
            while(n--){
                int curr = q.front();
                q.pop();

                farthestNode = curr; // curr node will be our farthestNode

                for(auto neig:adj[curr]){
                    if(!vis[neig]){
                        q.push(neig);
                        vis[neig] = 1;
                    }
                }
            }
            if(!q.empty()){
                dist++;
            }
        }

        return {farthestNode,dist};
    }

    int findDiameter(unordered_map<int,vector<int>> &adj){
        auto [farthestNode, dist] = BFS(adj,0); // bfs from 0 node (or any random node)

        auto [otherEndNode, diameter] = BFS(adj, farthestNode); 
        // bfs from the farthestNode we get from prev BFS to farthestNode we get from thsi call gives us diameter

        return diameter;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // Step 1 : Create a adj list
        unordered_map<int,vector<int>> adj1 = adjBuild(edges1);
        unordered_map<int,vector<int>> adj2 = adjBuild(edges2);

        // Step 2 : find diameter of both trees
        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int combinedDiameter = ((d1 + 1)/2 + (d2 + 1)/2 + 1); // mid of both + 1 edge

        return max({d1,d2,combinedDiameter});
    }
};
