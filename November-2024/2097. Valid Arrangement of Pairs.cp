class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // step 1 -> buidl adj list and other maps
        unordered_map<int, vector<int>> adj;

        // build indegree and outdegree to find starting point for graph(euler)
        unordered_map<int, int> outDegree;
        unordered_map<int, int> inDegree;
        // {node, indegree/outdegree}

        // filling adj, indegree and outdegree
        for(auto &edge:pairs){
            int u = edge[0];
            int v = edge[1];

            // filling adj
            adj[u].push_back(v);

            // filling indeg and outdeg
            inDegree[v]++;
            outDegree[u]++;
        }

        // step 2: find the startNode for traversal (outDeg - inDeg == 1)
        int startNode = pairs[0][0]; // we take any random node from pairs as initial
        for(auto &it:adj){
            int node = it.first;

            // check indeg and outdeg
            if(outDegree[node] - inDegree[node] == 1){
                // validf starting node for traversal
                startNode = node; // value is found and updated
                break;
            }
        }

        // simply do DFS
        vector<int> EulerPath; // final ans
        stack<int> st; // for dfs

        st.push(startNode); // initial Node

        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                // if ther eis edge for curr node to  proces in adj list
                int neig = adj[curr].back(); // take neig from back
                adj[curr].pop_back(); // popping it from back (adj list)
                // push in satck for traversal
                st.push(neig);
            }
            else{
                // no neig to process
                // push in euler path
                EulerPath.push_back(curr);

                // popping it
                st.pop();
            }
        }

        // step 3: building result
        reverse(EulerPath.begin(), EulerPath.end()); // as it is from stakc so it is reversed

        vector<vector<int>> res;

        for(int i = 0; i< EulerPath.size()-1; i++){
            res.push_back({EulerPath[i],EulerPath[i+1]});
        }

        return res;
    }
};
