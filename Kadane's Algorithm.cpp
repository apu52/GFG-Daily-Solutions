class Solution {
  public:
    long long maxSubarraySum(vector<int> &arr) {
        int n=arr.size();
        long long sum=0;
        long long maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxi=max(maxi,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};
