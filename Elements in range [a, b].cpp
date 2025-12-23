class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        vector<int> ans;
        
        sort(arr.begin(),arr.end());
        
        for(auto &q : queries){
            int l = q[0];
            int r = q[1];
            
            int lb = lower_bound(arr.begin(),arr.end(),l) - arr.begin();
            int ub = upper_bound(arr.begin(),arr.end(),r) - arr.begin();
            
            ans.push_back(ub-lb);
            
        }
        
        return ans;
    }
};
