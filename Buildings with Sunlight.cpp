class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        //track max element 
        if (arr.size()==0) return 0;
        
        int maxi=arr[0];
        int cnt=1;
        
        for (int i=1;i<arr.size();i++){
            if (arr[i]>=maxi){
                cnt++;
                maxi=arr[i];
                
            }
            
        }
        return cnt;
        
    }
};
