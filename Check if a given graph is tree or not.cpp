class Solution { 
  public: 
   
    bool helper(int u, int par, vector<int> &vis, vector<int> g[]){ 
        vis[u]=1; 
        bool flag = 1; 
        for (auto &c: g[u]){ 
            if (c==par) continue; 
            if (vis[c]) return false; 
            flag = flag & helper(c,u,vis,g); 
        } 
        return flag; 
    } 
   
    int isTree(int n, int m, vector<vector<int>> &adj) { 
        
        vector<int> g[n]; 
        for (int i=0; i<adj.size(); i++){ 
            g[adj[i][0]].push_back(adj[i][1]); 
            g[adj[i][1]].push_back(adj[i][0]); 
        } 
        vector<int> vis(n,0); 
        bool ans = helper(0,-1,vis,g); 
        for (auto &v: vis){ 
            if (v==0){ 
                ans = 0; break; 
            } 
        } 
        return ans; 
    } 
};
