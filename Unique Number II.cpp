class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> ans;
        unordered_map<int,int> map;
        
        for(int& num : arr){
            map[num]++;
        }
        for(auto& pair : map){
            if(pair.second == 1){
                ans.push_back(pair.first);
            }
        }
        if(ans[0] > ans[1]){
            swap(ans[0],ans[1]);
        }
        return ans;
    }
};
