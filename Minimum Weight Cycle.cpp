class Solution {
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        const int INF = 1e8;
        vector<vector<int>> dist(V, vector<int>(V, INF));
        vector<vector<int>> adj(V, vector<int>(V, INF)); 
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u][v] = adj[v][u] = min(adj[u][v], w); 
            dist[u][v] = dist[v][u] = min(dist[u][v], w); 
        }

        for (int i = 0; i < V; ++i) dist[i][i] = 0;

        int minCycle = INF;

        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < k; ++i) {
                for (int j = i + 1; j < k; ++j) {
                    if (dist[i][j] < INF && adj[i][k] < INF && adj[k][j] < INF) {
                        int cycleWeight = dist[i][j] + adj[i][k] + adj[k][j];
                        minCycle = min(minCycle, cycleWeight);
                    }
                }
            }
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        return (minCycle == INF) ? -1 : minCycle;
    }
};
