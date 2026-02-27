using ll = long long;

class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<ll>> ps(n, vector<ll>(m,0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ps[i][j] = mat[i][j];
                
                if(i > 0) ps[i][j] += ps[i - 1][j];
                if(j > 0) ps[i][j] += ps[i][j - 1];
                if(i > 0 && j > 0) ps[i][j] -= ps[i - 1][j - 1];
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int maxs = min(n - i , m - j);
                
                for (int size = 1; size <= maxs; size++) {
                    int r2 = i + size - 1;
                    int c2 = j + size - 1;
                    
                    ll sum = ps[r2][c2];
                    
                    if(i > 0) sum -= ps[i - 1][c2];
                    if(j > 0) sum -= ps[r2][j - 1];
                    if(i > 0 && j > 0) sum += ps[i - 1][j - 1];
                    
                    if(sum == x) cnt++;
                }
            }
        }
        return cnt;
    }
};
