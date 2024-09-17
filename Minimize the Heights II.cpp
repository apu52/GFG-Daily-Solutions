class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=arr[n-1]-arr[0];
        int l=arr[0]+k;
        int r=arr[n-1]-k;
        for(int i=0;i<(n-1);i++){
            int mini=min(l,arr[i+1]-k);
            int maxi=max(r,arr[i]+k);
            if(mini>=0)
            ans=min(ans,maxi-mini);
        }
        return ans;
    }
};
