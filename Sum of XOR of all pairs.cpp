class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        long long ans = 0;
        int n = arr.size();
     for(int i = 0; i < 32; i++) {
         long long count = 0;
         for(int j = 0; j < n; j++) {
             if(arr[j]&1 << i) count++;
         }
         ans += count * (n-count) * (1 << i);
     }
     return ans;
    }
};
