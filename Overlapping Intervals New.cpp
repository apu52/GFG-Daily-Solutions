class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        ans.push_back({arr[0][0], arr[0][1]});
        int co = 0;
        for(int i = 1; i<n; i++){
            int last = ans[co][1];
            if(last >= arr[i][0]){
                ans[co][1] = max(ans[co][1], arr[i][1]);
            }
            else{
                ans.push_back({arr[i][0], arr[i][1]});
                co++;
            }
        }
        
        
        return ans;
    }
};
