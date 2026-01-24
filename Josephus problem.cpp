class Solution {
  public:
    int josephus(int n, int k) {
        int ans = 0; // Josephus(1, k) = 0 in 0-based indexing
        
        for(int i = 2; i <= n; i++){
            ans = (ans + k) % i;
        }
        
        return ans + 1; // convert to 1-based indexing
    }
};
