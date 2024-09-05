class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {

        int xor1 = 0, xor2 = 0;
        
        for (int i = 1; i <= n; i++)
            xor1 = xor1 ^ i;
        
        for (int i = 0; i < n - 1; i++)
            xor2 = xor2 ^ arr[i];
        
        return xor1 ^xor2;
    }
};
