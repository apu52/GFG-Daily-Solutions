class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp;
        
        // Store indices of each value
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
        
        vector<int> result;
        
        for(auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int x = q[2];
            
            if(mp.find(x) == mp.end()) {
                result.push_back(0);
                continue;
            }
            
            // Binary search on indices of x
            auto left = lower_bound(mp[x].begin(), mp[x].end(), l);
            auto right = upper_bound(mp[x].begin(), mp[x].end(), r);
            
            result.push_back(right - left);
        }
        
        return result;
    }
};
