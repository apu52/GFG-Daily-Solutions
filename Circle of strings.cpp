class Solution {
  public:
     vector<vector<int>> g;
     vector<int> vis;
    void dfs(int node) {
        vis[node] = 1;
        for(auto v:g[node]) {
            if(!vis[v]) {
                dfs(v);
            }
        } 
    }
    int isCircle(vector<string> A)
    {
        g.clear();
        g.resize(26);
        vis.clear();
        vis.assign(26,0);
        
        int start;
        for(auto it: A) {
            int u = it[0]-'a';
            int v = it[it.size()-1]-'a';
            g[u].push_back(v);
            g[v].push_back(u);
            start = u;
        }
        
        dfs(start);
        for(int i=0;i<26;i++) {
            if(!vis[i] && g[i].size()>0) return 0;
            if(g[i].size()%2==1) return 0;
        }
        return 1;
        


    }
};
