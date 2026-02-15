class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        int n = a.size();
        
        // Edge case
        if (m == 0 || n == 0) return 0;
        if (m > n) return -1;
        
        sort(a.begin(), a.end());
        
        int ans = INT_MAX;
        
        for (int i = 0; i <= n - m; i++) {
            ans = min(ans, a[i + m - 1] - a[i]);
        }
        
        return ans;
    }
};
