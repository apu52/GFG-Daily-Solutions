class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int l = 0, r = n - 1;
        int res = 0;
        int maxLeft = arr[l], maxRight = arr[r];
        while(l < r){
            if(arr[l] < arr[r]){
                l++;
                maxLeft = max(maxLeft, arr[l]);
                res += maxLeft - arr[l];
            }
            else{
                r--;
                maxRight = max(maxRight, arr[r]);
                res += maxRight - arr[r];
            }
        }
        return res;
    }
};
