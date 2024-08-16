class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maxCutUtils(int n, int x, int y, int z, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }
        
        if (n < 0) {
            return -1;
        }
        
        if (dp[n] != -1) {
            return dp[n];
        }
        
        int cutX = maxCutUtils(n - x, x, y, z, dp);
        int cutY = maxCutUtils(n - y, x, y, z, dp);
        int cutZ = maxCutUtils(n - z, x, y, z, dp);
        
        int maxVal = max(cutX, max(cutY, cutZ));
        
        if (maxVal == -1) {
            dp[n] = -1;
        } else {
            dp[n] = maxVal + 1;
        }
        
        return dp[n];
    }

    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n + 1, -1);
        maxCutUtils(n, x, y, z, dp);
        return dp[n] == -1 ? 0 : dp[n];
    }
};
