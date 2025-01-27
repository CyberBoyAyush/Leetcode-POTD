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


// Approach 3 -> Topo Sort with preq list
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // creating adj list and calculating indegree
        unordered_map<int, vector<int>> adj;

        vector<int> inDeg(numCourses, 0); // initial indegree will be 0

        for(auto &edge : prerequisites){
            int u = edge[0];
            int v = edge[1];

            //u --> v
            adj[u].push_back(v);
            inDeg[v]++; // indegree of v increased
        }

        queue<int> q; // for topo sort

        for(int i = 0; i<numCourses; i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }

        // creation of list -> topo
        unordered_map<int, unordered_set<int>> mpp;

        // standard topo template
        while(!q.empty()){
            int node = q.front();
            q.pop();

            // going to neighbours
            for(auto &ngbr : adj[node]){
                // we have the node and neigh we update the preq list
                mpp[ngbr].insert(node);

                // finding preq of node also to put in list -> imp for ques
                for(auto &preq : mpp[node]){
                    mpp[ngbr].insert(preq);
                }

                // reducing indegree
                inDeg[ngbr]--;
                if(inDeg[ngbr] == 0){
                    // push in queue
                    q.push(ngbr);
                }
            }
        }

        // Now processing queries
        int Q = queries.size();
        vector<bool> ans(Q,false);

        for(int i = 0; i<Q; i++){
            int src = queries[i][0];
            int dest = queries[i][1];

            bool reacheable = mpp[dest].contains(src); // finding preq in mpp (topo)
            ans[i] = reacheable;
        }

        return ans;
    }
};
