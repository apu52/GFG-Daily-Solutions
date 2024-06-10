class Solution {
  public:
    void matchPairs(int n, char nuts[], char bolts[]) {
        sort(nuts,nuts+n);
        sort(bolts,bolts+n);
    }
};
