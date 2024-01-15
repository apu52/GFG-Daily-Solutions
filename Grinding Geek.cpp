class Solution{
    public:
    int dp[1002][1002];
    int func(int n, int t, vector<int> &cost, int i){
        if(i==n){
            return 0;
        }
        if(t<=0) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        int take = 0, notTake = 0;
        if(t>=cost[i]){
            take = 1+ func(n, t - cost[i]/10.0, cost, i+1);
        }
        notTake = func(n, t, cost, i+1);
        return dp[i][t] = max(take, notTake);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        memset(dp, -1, sizeof(dp));
        return func(n, total, cost, 0);
    }
};
