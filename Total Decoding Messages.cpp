class Solution {
  public:
    int solveUsingRe(string&s,int i,int&n){
        if(i>=n) return 1;
        if(s[i]=='0') return 0;
        int take_ith_ch=solveUsingRe(s,i+1,n);
        int not_take_ith_ch=0;
        if(i+1<n)
        if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
            not_take_ith_ch=solveUsingRe(s,i+2,n);
        }
        return take_ith_ch+not_take_ith_ch;
    }
    int solveUsingMem(string&s,int i,int&n,vector<int>&dp){
        if(i>=n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int take_ith_ch=solveUsingMem(s,i+1,n,dp);
        int not_take_ith_ch=0;
        if(i+1<n)
        if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
            not_take_ith_ch=solveUsingMem(s,i+2,n,dp);
        }
         dp[i]=take_ith_ch+not_take_ith_ch;

         return dp[i];
    }
    int tabulation(string&s){
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
          if(s[i]=='0') dp[i]= 0;
        else{
         int take_ith_ch=dp[i+1];
        int not_take_ith_ch=0;
        if(i+1<n)
        if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
            not_take_ith_ch=dp[i+2];
        }
         dp[i]=take_ith_ch+not_take_ith_ch;

        }
        }
         return dp[0];
    }
    int spaceOpti(string&s){
        int n=s.size();
        // vector<int>dp(n+1,0);
        int curr=0;
        int next1=0;
        int next2=0;
          next1=1;
        for(int i=n-1;i>=0;i--){
          if(s[i]=='0') curr= 0;
        else{
         int take_ith_ch=next1;
        int not_take_ith_ch=0;
        if(i+1<n)
        if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
            not_take_ith_ch=next2;
        }
         curr=take_ith_ch+not_take_ith_ch;

        }
        next2=next1;
        next1=curr;
        }
         return next1;
    }
    int countWays(string &s) {
         int n=s.length();
        vector<int>dp(n+1,-1);
        // return solveUsingRe(s,0,n);
        // return solveUsingMem(s,0,n,dp);
        // return tabulation(s);
        return spaceOpti(s);
    }
};
