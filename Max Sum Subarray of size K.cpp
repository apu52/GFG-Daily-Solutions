class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int sum = 0;
        int ans = 0;
        int i = 0;
        int n = arr.size();
        
        for (int j=0; j<n; j++) {
            sum += arr[j];
            
            if (j-i+1 == k) {
                ans = max(ans, sum);
                sum -= arr[i];
                i++;
            }
        }
        
        return ans;
    }
};
