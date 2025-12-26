class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
         int n=arr.size();
        int ans=n;
        int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]-mid-1>=k){
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
            
        }
        return ans+k;
    }
};
