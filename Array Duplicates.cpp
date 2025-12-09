class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto a:arr){
           mp[a]++;
            if(mp[a]==2)
            ans.push_back(a);
        }
     return ans;       
    }
};
