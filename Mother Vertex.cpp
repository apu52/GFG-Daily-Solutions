class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){

        vis[node] = 1;

        for(auto neigh : adj[node]){

            if(!vis[neigh]){
                dfs(neigh, adj, vis);
            }
        }
    }

    int findMotherVertex(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        for(auto &e : edges){

            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(V,0);

        int candidate = 0;

        // find candidate
        for(int i=0;i<V;i++){

            if(!vis[i]){

                dfs(i, adj, vis);

                candidate = i;
            }
        }

        // verify candidate
        fill(vis.begin(), vis.end(), 0);

        dfs(candidate, adj, vis);

        for(int x : vis){

            if(!x) return -1;
        }

        return candidate;
    }
};
