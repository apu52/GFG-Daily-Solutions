class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        if (n == 1 && m == 1) return 0;
  if (n == 1 || m == 1) return 1;
  int result = 0;
  int i = 1;
  int j = 1;
  while (i <= n) {
   while (j <= m) {
    result = (result + ((n - i)*m + m - j));
    if ((j + 2) <= m && (i + 1) <= n)result--;
    if ((j - 2) >= 1 && (i + 1) <= n)result--;
    if ((i + 2) <= n && (j + 1) <= m)result--;
    if ((i + 2) <= n && (j - 1) >= 1)result--;
    j++;
   }
   i++;
   j = 1;
  }
  return (result*2);
    }
};
