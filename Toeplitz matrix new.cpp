class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n; i++){
            int k =  i, j = 0;
            while(k<n-1 and j<m-1){
                if(mat[k][j]!=mat[k+1][j+1]) return 0;
                k++;
                j++;
            }
        }
        
        for(int j = 1; j<m; j++){
            int i = 0, k  = j;
            while(i<n-1 and k<m-1){
                if(mat[i][k]!=mat[i+1][k+1]) return 0;
                k++;
                i++;
            }
        }
        
        return 1;
    }
};
