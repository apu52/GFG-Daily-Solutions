class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        long long ans=1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>ans){
                return ans;
            }
            else{
                ans=ans+arr[i];
            }
        }
        return ans;
    }
};
