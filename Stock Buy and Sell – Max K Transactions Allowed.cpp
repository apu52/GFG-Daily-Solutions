class Solution {
  public:
    int maxProfit(vector<int>& ar, int k) {
        // code here
        int n  = ar.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        
        function<int(int, int, int)> rec = [&](int ind, int buy, int tot)->int{
            if(tot == 0 or ind == n) return 0;
            if(dp[ind][tot][buy] != -1) return dp[ind][tot][buy];
            
            int take = 0, notake = 0;
            
            if(buy) {
                int one = -ar[ind] + rec(ind+1, 0, tot);
                int two = rec(ind+1, 1, tot);
                take = max(one, two);
            }
            else {
                int one = ar[ind] + rec(ind+1, 1, tot-1);
                int two = rec(ind+1, 0, tot);
                notake = max(one, two);
            }
            
            return dp[ind][tot][buy] = max(take, notake);
            
        };
        return rec(0, 1, k);
        
    }
};
