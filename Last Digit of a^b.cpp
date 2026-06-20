class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        // Special case: a^0 = 1
        if (b == "0") return 1;

        int lastDigit = a.back() - '0';

        // Compute b % 4
        int mod = 0;
        for (char c : b) {
            mod = (mod * 10 + (c - '0')) % 4;
        }

        // If divisible by 4, use exponent 4
        int exp = (mod == 0) ? 4 : mod;

        int ans = 1;
        for (int i = 0; i < exp; i++) {
            ans = (ans * lastDigit) % 10;
        }

        return ans;
    }
};
