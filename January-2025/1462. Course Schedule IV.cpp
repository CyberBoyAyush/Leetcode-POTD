// Approach 1 -> Simple DFS and Check
class Solution {
public:

    bool dfs(int src, int dest, vector<bool> &vis, unordered_map<int,vector<int>> &adj){
        vis[src] = true; // marking visited

        if(src == dest){
            return true;
        }

        bool flag = false;
        for(auto &adjNode : adj[src]){
            if(!vis[adjNode]){
                flag = flag || dfs(adjNode, dest, vis, adj);
            }
        }

        return flag;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;

        // creating adj list
        for(auto edge: prerequisites){
            int u = edge[0];
            int v = edge[1];

            // directed egde u-->v
            adj[u].push_back(v);
        }

        // creating queries and ans
        int Q = queries.size();

        vector<bool> ans(Q);

        for(int i = 0; i<Q; i++){
            // Source and Dest
            int u = queries[i][0];
            int v = queries[i][1];

            vector<bool> vis(numCourses, false);
            ans[i] = dfs(u,v,vis,adj);
        }

        return ans;
    }
};

// Approach 2 -> Preprocess
class Solution {
public:

    bool dfs(int src, int dest, vector<bool> &vis, unordered_map<int,vector<int>> &adj){
        vis[src] = true; // marking visited

        if(src == dest){
            return true;
        }

        bool flag = false;
        for(auto &adjNode : adj[src]){
            if(!vis[adjNode]){
                flag = flag || dfs(adjNode, dest, vis, adj);
            }
        }

        return flag;
    }

    void preProcess(vector<vector<bool>> &grid, unordered_map<int,vector<int>> &adj, int n){
        for(int u = 0; u<n ;u++){
            for(int v = 0; v<n ; v++){
                if(u != v){
                    vector<bool> vis(n,false);
                    grid[u][v] = dfs(u,v,vis,adj);
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;

        // creating adj list
        for(auto edge: prerequisites){
            int u = edge[0];
            int v = edge[1];

            // directed egde u-->v
            adj[u].push_back(v);
        }

        // Preprocessing
        vector<vector<bool>> grid(numCourses, vector<bool>(numCourses, false));
        preProcess(grid, adj, numCourses);

        // creating queries and ans
        int Q = queries.size();

        vector<bool> ans(Q);

        for(int i = 0; i<Q; i++){
            // Source and Dest
            int u = queries[i][0];
            int v = queries[i][1];

            ans[i] = grid[u][v];
        }

        return ans;
    }
};
