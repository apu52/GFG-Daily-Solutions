class Solution {
  public:
    int getSingle(vector<int>& arr) {
        int res = 0;
        
        for(auto& x : arr){
            res ^= x;
        }
        
        return res;
    }


};
