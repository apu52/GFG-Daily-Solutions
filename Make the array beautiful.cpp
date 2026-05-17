class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        int n = arr.size();
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(ans.empty()) {
                ans.push_back(arr[i]);
            }
            else if((arr[i] < 0 && ans.back() < 0) || (arr[i] >= 0 && ans.back() >= 0)) {
                ans.push_back(arr[i]);
            }
            else {
                ans.pop_back();
            }
        }
        return ans;
    }
};
