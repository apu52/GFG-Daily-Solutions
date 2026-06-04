class Solution {
  public:
    int maxSubstring(string &s) {
        int z = 0, o = 0, ans = -1;
        for (char ch : s) {
            if (ch == '1') o++;
            else z++;
            int dif = z - o;
            ans = max(ans, dif);
            if (dif < 0) z = 0,  o = 0;
        }
        return ans;
    }
};
