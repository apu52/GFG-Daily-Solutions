class Solution {
  public:
    bool isBitSet(int n) {
        long long i=1;
        while(i<n)
            i=(i<<1)+1;
        return i==n;
    }
};
