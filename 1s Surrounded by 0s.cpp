class Solution {
  public:
  
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited){
        
        int n = grid.size(), m = grid[0].size();
        visited[row][col] = 1;
        
        //check for to[. right, bottom, left]
        if(row!=0){
            if(!visited[row-1][col] && grid[row-1][col]==1){
                dfs(row-1, col, grid, visited);            
            }
        }
        
        if(row!=n-1){
            if(!visited[row+1][col] && grid[row+1][col]==1){
                dfs(row+1, col, grid, visited);            
            }
        }
        
        if(col!=0){
            if(!visited[row][col-1] && grid[row][col-1]==1){
                dfs(row, col-1, grid, visited);            
            }
        }
        
        if(col!=m-1){
            if(!visited[row][col+1] && grid[row][col+1]==1){
                dfs(row, col+1, grid, visited);            
            }
        }
        
    }
  
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(), m = grid[0].size(), count=0;
        vector<vector<int>> visited(n, vector<int>(m,0));
        
        for(int j=0; j<m; j++){
            if(!visited[0][j] && grid[0][j]==1){
                dfs(0, j, grid, visited);
            }
            
            if(!visited[n-1][j] && grid[n-1][j]==1){
                dfs(n-1, j, grid, visited);                
            }
        }
        
        for(int i=0; i<n; i++){
            
            if(!visited[i][0] && grid[i][0]==1){
                dfs(i, 0, grid, visited);
            }
            
            if(!visited[i][m-1] && grid[i][m-1]==1){
                dfs(i, m-1, grid, visited);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && visited[i][j]==0)
                    count++;
            }
        }
        
        return count;
    }
};
