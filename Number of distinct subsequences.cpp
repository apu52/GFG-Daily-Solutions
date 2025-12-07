class Solution {
  public:
    int distinctSubseq(string &str) {
        // code here
        int n=str.size();
        int mod=1e9+7;
        vector<long long> dp(n+1,0);
        vector<int> last(26,-1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=(2*dp[i-1])%mod;
            int ch=str[i-1]-'a';
            if(last[ch]!=-1){
                dp[i]=(dp[i]-dp[last[ch]-1]+mod)%mod;
            }
            last[ch]=i;
        }
        return dp[n];
    }
};
