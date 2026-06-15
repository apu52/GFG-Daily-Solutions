class Solution {
public:
    int minimumCost(vector<int>& cost, int w) {
        // Use a large value for infinity. 
        // 1e9 is safe given constraints.
        int inf = 1e9;
        vector<int> dp(w + 1, inf);
        
        dp[0] = 0;
        
        // Iterate through all capacities from 1 to w
        for (int j = 1; j <= w; j++) {
            // Check all available packets
            for (int i = 0; i < cost.size(); i++) {
                int weight = i + 1;
                if (cost[i] != -1 && weight <= j) {
                    if (dp[j - weight] != inf) {
                        dp[j] = min(dp[j], dp[j - weight] + cost[i]);
                    }
                }
            }
        }
        
        return (dp[w] == inf) ? -1 : dp[w];
    }
};
