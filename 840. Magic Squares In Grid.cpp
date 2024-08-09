class Solution {
  public:
    int mod =1e9 +7;
    int Maximize(vector<int> &arr) {
        int n =arr.size();
        sort(arr.begin(),arr.end());
        int sum =0;
        for(int i =0;i< n;i++){
            sum = (sum + 1ll*i*arr[i])%mod;
        }
        return sum;
    }
};
