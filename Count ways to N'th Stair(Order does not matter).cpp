class Solution{
 public:
 
    
  int nthStair(int n){
      //  Code here
      int dp[n+1];
      for(int i=0;i<=n;i++) dp[i]=0;
      dp[0]=1;
      for(int step=1;step<=2;step++){
          for(int i=1;i<=n;i++){
              if(i>=step)
              dp[i]+=dp[i-step];
          }
      }
      
      return dp[n];
  }
};
