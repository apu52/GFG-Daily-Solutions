class Solution {
  public:
    int optimalKeys(int n) {
        // code here
        long long int dp[n];
        if(n<6)return n;
        for(int i=0;i<6;i++)
        dp[i]=i+1;
        for(int i=6;i<n;i++)
        dp[i]=max(2*dp[i-3],max(3*dp[i-4],4*dp[i-5]));
        return dp[n-1];
    }
};
