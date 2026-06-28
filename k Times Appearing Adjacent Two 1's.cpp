class Solution {
  public:
    int mode=1000000007;
    
    virtual int svc(int n, int k, int prev, vector<vector<vector<int>>> &dp){
      if(k<0) return 0;
      if(n==0) return (k==0)? 1: 0;
      
      if(dp[n][k][prev] != -1) return dp[n][k][prev];
      
      if(prev==0){
        return dp[n][k][prev] = (svc(n-1, k, 0, dp) + svc(n-1, k, 1, dp))%mode;  
      }  
      return dp[n][k][prev] = (svc(n-1, k, 0, dp) + svc(n-1, k-1, 1, dp))%mode;
    }
    
    virtual int countStrings(int n, int k){
      vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
      return svc(n, k, 0, dp);
    }
};
