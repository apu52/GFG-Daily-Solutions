class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        if (arr.size() < 2) {
            // If the size of the array is less than 2, we can't form any subarray of size greater than one.
            return -1;
        }
        
        int maxSum = INT_MIN;
        
        // Iterate over the array to consider every adjacent pair
        for (int i = 1; i < arr.size(); i++) {
            // Calculate the sum of the current adjacent pair
            int currentSum = arr[i] + arr[i-1];
            // Update maxSum if currentSum is greater
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};
