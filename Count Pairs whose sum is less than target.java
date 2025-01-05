class Solution {
    int countPairs(int arr[], int target) {
        Arrays.sort(arr);
        int ans=0, n=arr.length;
        for(int i=0;i<n;i++){
            int upperbound = bs(arr,i,n-1,target-arr[i]);
            
            ans += upperbound-i;
        }
        return ans;
    }
    int bs(int a[],int l,int r,int x){
        int ans=l;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(a[mid]<x){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
}
