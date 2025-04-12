class Solution {
  public:
    void bfs(int row, int col, int m, int n, int newColor, int iniColor, vector<vector<int>>& image, vector<vector<int>>& vis){
        vis[row][col] = newColor;
        int delrow[] = {-1, 0, 1, 0}, delcol[] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({row, col});
        
        while(!q.empty()){
            int row = q.front().first, col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = row+delrow[i], ncol = col+delcol[i];
                if(nrow >= 0  &&  ncol >= 0  &&  nrow < m  &&  ncol < n  &&  image[nrow][ncol] == iniColor  &&  vis[nrow][ncol] != newColor)
                    bfs(nrow, ncol, m, n, newColor, iniColor, image, vis);
            }
        }
        
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int m = image.size(), n = image[0].size();
        vector<vector<int>> vis = image;
        int iniColor = image[sr][sc];
        
        bfs(sr, sc, m, n, newColor, iniColor, image, vis);
        return vis;
    }
};
