class Solution {
  public:
  void dfs(int node, int parent, vector<int> adj[], vector<int>& vis,
             vector<int>& tin, vector<int>& low, int& timer,
             vector<int>& mark) {
        
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;

        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, node, adj, vis, tin, low, timer, mark);
                low[node] = min(low[node], low[it]);

                // Articulation condition
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }

                child++;
            } else {
                // back edge
                low[node] = min(low[node], tin[it]);
            }
        }

        // root node case
        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];

        // Build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(V, 0), tin(V), low(V), mark(V, 0);
        int timer = 0;

        // Handle disconnected graph
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, tin, low, timer, mark);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (mark[i]) ans.push_back(i);
        }

        if (ans.size() == 0) return {-1};
        return ans;
    }
};
