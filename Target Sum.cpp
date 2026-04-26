class Solution {
  public:
  int dp[101][2001];
  int solve(int i, int sum, vector<int>& arr, int target){
      if(i==arr.size())return sum==target;
      if(dp[i][sum+1000]!=-1)return dp[i][sum+1000];
      int plus=solve(i+1,sum+arr[i],arr,target);
       int minus=solve(i+1,sum-arr[i],arr,target);
       return dp[i][sum+1000]=plus+minus;
      
  }
    int totalWays(vector<int>& arr, int target) {
          memset(dp, -1, sizeof(dp));
            return solve(0, 0, arr, target);
        
    }
};
