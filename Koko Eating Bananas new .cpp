class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        int n = arr.size();
        int start = 1, end = 1e7, ans = 1e7;
        while(start<=end){
            int mid = start + (end - start)/2, ct = 0;
            for(auto& it:arr){
                ct+=(it+mid-1)/mid;
            }
            if(ct<=k){
                ans = min(ans, mid);
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};
