class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for (int i=0;i<n;i++) sum+=arr[i];
        int sum1=sum,sum2=0;
        for (int m=n-1;m>=0;m--)    {
            sum2+=arr[m];
            sum1-=arr[m];
            if (sum1==sum2) return true;
        }
        return false;
    }
};
