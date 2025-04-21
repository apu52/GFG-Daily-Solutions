class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here'
        
        int n = arr.size();
        
        map<int,int> mp;
        
        for(int i=0; i< n; i++){
            mp[arr[i]]++;
        }
        
        for(int i=1; i<= n+1;i++){
            
            if (mp[i] == 0){
                return i;
            }
        }
        
        return -1;
        
        
    }
};
