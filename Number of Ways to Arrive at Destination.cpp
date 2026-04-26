class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        const int MOD = 1e9 + 7;
        
        // Adjacency list
        vector<pair<int,int>> adj[V];
        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        // Distance and ways array
        vector<long long> dist(V, LLONG_MAX);
        vector<int> ways(V, 0);
        
        // Min heap (distance, node)
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            
            if(d > dist[node]) continue;
            
            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int weight = it.second;
                if(d + weight < dist[adjNode]) {
                    dist[adjNode] = d + weight;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                // Found another shortest path
                else if(d + weight == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[V - 1];
        
    }
};
