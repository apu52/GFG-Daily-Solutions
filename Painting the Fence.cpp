class Solution {
  public:
    int countWays(int n, int k) {
        // code here
        
        if (n == 1) return k;
        
        long long same = 0;
        long long diff = k;
        
        for (int i = 2; i <= n; i++) {
            long long new_same = diff;
            long long new_diff = (same + diff) * (k - 1);
            
            same = new_same;
            diff = new_diff;
        }
        
        return same + diff;
    }
};
