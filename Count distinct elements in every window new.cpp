class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>mp;
        int maxi =INT_MIN;
        vector<int>ans;
        int j = 0;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
            if(i-j+1==k){
               ans.push_back(mp.size());
                mp[arr[j]]--;
                if(mp[arr[j]]==0){
                    mp.erase(arr[j]);
                }
                j++;
            }
        }

        return ans;
        
    }
};
