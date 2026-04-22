class Solution {
  public:
    vector<int> findMean(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        // build prefix sum
        vector<long long> prefix(n);
        prefix[0] = arr[0];
        
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }
        
        vector<int> ans;
        
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            
            long long sum = prefix[r];
            if (l > 0) sum -= prefix[l-1];
            
            int len = r - l + 1;
            ans.push_back(sum / len);  // floor automatically
        }
        
        return ans;
    }
};
