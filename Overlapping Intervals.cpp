class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> merged;

       
        for (auto& interval : arr) {
            
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        
        return merged;
    }
};
