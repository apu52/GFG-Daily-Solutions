class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            if(arr[i] == 0){
                arr[i] = -1;
            }
        }
        
        unordered_map<int,int> mp;
        int res = 0;
        int presum = 0;
        
        for(int i=0;i<n;i++){
            presum += arr[i];
            
            if(presum == 0){
                res = i+1;
            }
            
            if(mp.find(presum) == mp.end()){
                mp[presum] = i;
            }
            
            if(mp.find(presum) != mp.end()){
                res = max(res,i-mp[presum]);
            }
        }
        return res;
    }
};
