class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        int xr = 0;
        vector<int> arr;
        
        // Initial array contains 0
        arr.push_back(0);
        
        for (auto &q : queries) {
            int type = q[0];
            int x = q[1];
            
            if (type == 0) {
                arr.push_back(x ^ xr);
            } else {
                xr ^= x;
            }
        }
        
        vector<int> ans;
        for (int val : arr) {
            ans.push_back(val ^ xr);
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
