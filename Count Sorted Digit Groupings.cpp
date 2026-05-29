class Solution {
  public:
  
    int dp[101][1000];
    
    int solve(string &s, int idx, int prevSum)
    {
        if(idx == s.size())
            return 1;
            
        if(dp[idx][prevSum] != -1)
            return dp[idx][prevSum];
            
        int ans = 0;
        int currSum = 0;
        
        for(int i = idx; i < s.size(); i++)
        {
            currSum += (s[i] - '0');
            if(currSum >= prevSum)
            {
                ans += solve(s, i + 1, currSum);
            }
        }
        
        return dp[idx][prevSum] = ans;
    }
  
    int validGroups(string &s) {
        
        memset(dp, -1, sizeof(dp));
        
        return solve(s, 0, 0);
    }
};
