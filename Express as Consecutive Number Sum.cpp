class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        // code here
        return !((n > 0) && ((n & (n - 1)) == 0));

    }
};
