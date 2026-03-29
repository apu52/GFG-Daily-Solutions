class Solution {
  public:
    int noOfWays(int index, vector<int>& arr, int n, int sum, vector<vector<int>>& dp){
        
        if(index == n){
            return (sum == 0) ? 1 : 0;
        }
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        int exclude = noOfWays(index+1, arr, n, sum, dp);
        int include = 0;
        if(sum - arr[index] >= 0){
            include = noOfWays(index + 1, arr, n, sum - arr[index], dp);
        }
        return dp[index][sum] = include + exclude;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        
        // s1 = ((total) + diff) / 2 ;
        int n = arr.size();
        int sum = 0;
        for(int x : arr){
            sum += x;
        }
        if((sum + diff)%2 != 0 || sum < diff){
            return 0;
        } 
        sum = (sum + diff) / 2;
        vector<vector<int>> dp(n+1, vector<int>(sum + 1, -1));
        return noOfWays(0, arr, n, sum, dp);
    }
};
