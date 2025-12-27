class Solution {
  public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        
        int low = mat[0][0];
        int high = mat[n-1][n-1];
        int ans = low;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            
            // Count elements <= mid
            for (int i = 0; i < n; i++) {
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            
            if (count >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
