class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int curr=0;
        int l=arr.size();
        for(int i=0;i<k;i++) curr^=arr[i];
        int res=curr;
        for(int i=k;i<l;i++){
            curr= curr^arr[i-k]^arr[i];
            res=max(res,curr);
            
        }
        return res;
    }
};
