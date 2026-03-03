class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i =0, j= 0;
        unordered_map<int,int> mp;
        int ans = 0;
        while(i<n){
               mp[arr[i]]++;
               if(mp.size()>2){
                     while(j<n && mp.size() > 2){
                         mp[arr[j]]--;
                         if(mp[arr[j]] == 0){
                               mp.erase(arr[j]);
                               
                         }
                         j++;
                     }
               }else{
                     ans = max(ans,i-j+1);
               }
               i++;
        }
        return ans;
    }
};
