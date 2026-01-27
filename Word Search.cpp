class Solution {
  public:
  
    int n,m;
  
    int r[4]={0,0,1,-1};
    int c[4]={1,-1,0,0};
  
    bool isValid(int x,int y)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
  
    bool dfs(int i,int x,int y,vector<vector<char>> &mat,string &s)
    {
        if(i==s.size())
            return 1;
        char temp=mat[x][y];
        mat[x][y]='(';
        for(int k=0;k<4;k++)
        {
            int nx=x+r[k];
            int ny=y+c[k];
            if(isValid(nx,ny) && s[i]==mat[nx][ny])
                if(dfs(i+1,nx,ny,mat,s))
                    return 1;
        }
        mat[x][y]=temp;
        return 0;
    }
    
  
    bool isWordExist(vector<vector<char>> &mat, string &s) {
        n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j]==s[0])
                    if(dfs(1,i,j,mat,s))
                        return 1;
        return 0;
    }
};
