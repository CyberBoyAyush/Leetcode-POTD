class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // creating adj list
        unordered_map<int,vector<pair<int,double>>> adj;
        vector<double> result(n,0);

        // pushing values in adj list
        for(int i = 0; i<edges.size() ;i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
        }

        // craeting pq (MAX HEAP)
        priority_queue<pair<double,int>> pq;

        //pushing initial prob and start nodes in pq
        pq.push({1.0,start_node}); // priotiy of reaching from start node to start node iwll be 1 ()100%
        result[start_node] = 1.0;

        while(!pq.empty()){
            int currNode = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();

            // going in neighbours 
            for(auto &temp : adj[currNode]){
                double nProb = temp.second;
                int adjNode = temp.first;

                if(result[adjNode] < currProb * nProb){
                    // because in prob we multiply it
                    result[adjNode] = currProb * nProb;
                    pq.push({result[adjNode],adjNode});
                }
            }
        }

        return result[end_node];
         
    }
};
