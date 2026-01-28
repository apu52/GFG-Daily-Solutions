int sx[50];
class Solution {
  private:
  int ret{};
  
  public:
    int n;
  vector<vector<int>>dp; 
  int solve(vector<int> &arr, int k, int i ){
      
      if(k < 0) return 0; 
      if( i == n-1){
          if(k == 0 )
          return arr[i] == 0 ? 2 : 1;
          else return arr[i] == k ? 1 : 0 ;
      }
      
      if(dp[i][k]!=-1) return dp[i][k];
       
       int take = 0 ; 
       if(arr[i] <= k && arr[i] >= 0 )
       take = solve(arr, k - arr[i], i + 1);
       int not_take = solve(arr, k , i + 1);
       
       return dp[i][k] =  take + not_take; 
      
      
  }
  
    int countSubset(vector<int> &arr, int k) {
         n = arr.size();
         dp.assign(n, vector<int>(k + 1, -1));
         return solve(arr, k , 0);
    }
};
