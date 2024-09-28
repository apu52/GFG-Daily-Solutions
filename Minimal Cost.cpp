class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        int dp[n];
        for(int i=0;i<n;i++) dp[i]=1e9;
        dp[0]=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    dp[i]= min(dp[i], dp[i-j]+ abs(arr[i-j]-arr[i]));
                }
            }
            
            // cout<<dp[i]<<" ";
            
            
        }
        
        return dp[n-1];
        
    }
};
