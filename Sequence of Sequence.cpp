class Solution{ 
public: 
    int solve(int i,int j,int n,int m,vector<vector<int>>&dp) 
    { 
        if(j==0) 
            return 1; 
        if(i>m) 
            return 0; 
        if(dp[i][j]!=-1) 
            return dp[i][j]; 
        int take=solve(i*2,j-1,n,m,dp); 
        int not_take=solve(i+1,j,n,m,dp); 
        return dp[i][j]=take+not_take; 
    } 
    int numberSequence(int m, int n){ 
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1)); 
        return solve(1,n,n,m,dp); 
    } 
};
