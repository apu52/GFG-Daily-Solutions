class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> diff(n, 0);
        int currFlip = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            currFlip += diff[i];
            int bit = arr[i];
            if(currFlip % 2 == 1) {
                bit ^= 1;
            }
            if(bit == 0) {
                ans++;
                currFlip++;
                if(i + k > n)  return -1;
                if(i + k < n)   diff[i + k] -= 1;
            }
        }
        return ans;
    }
};
