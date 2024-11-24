class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        long long max_sum = arr[0];
        long long current_sum = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            current_sum = max((long long)arr[i], current_sum + arr[i]);
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};
