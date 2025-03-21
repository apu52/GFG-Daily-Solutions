class Solution {
    int n;
    
public:
    int findMaxSum(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n + 4, 0);
        
        for(int index = n-1; index >= 0; --index)
            dp[index] = max(dp[index + 1], nums[index] + dp[index + 2]);
        
        return dp[0];
    }
};
