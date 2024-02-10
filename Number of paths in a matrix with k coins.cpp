class Solution {
public:
    long long help(int i, int j,int k, vector<vector<int>> &arr,vector<vector<vector<int>>> &dp) {
        if(i < 0 || j < 0) return 0;
        int c = arr[i][j];
        k -= c;
        if(k < 0) return 0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(i == 0 && j == 0) {
            if(k == 0) return 1;
        }
        return dp[i][j][k] = help(i-1,j,k,arr,dp) + help(i,j-1,k,arr,dp);
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        vector<vector<vector<int>>> dp;
        
        dp.resize(n , vector<vector<int>>(n , vector<int>(k, -1)));
        
        long long paths = 0;
        // We start at the  n-1,n-1 cell
        paths = help(n-1,n-1,k,arr,dp);
        
        return paths;
    }
};
