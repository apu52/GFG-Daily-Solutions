class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int s = 0;
        for(int i=0; i<n; i++) {
            s += i*arr[i];
        }
        int sum = accumulate(arr.begin(),arr.end(),0);
        int result = s;
        for(int i=n-1; i>0; i--) {
            s = s - ((n-1)*arr[i]) + (sum-arr[i]);
            result = max(result,s);
        }
        return result;
    }
};
