class Solution {
  public:
    map<pair<int, int>, vector<int>> mp;
    int countWays(string &s) {
        // code here
        return solve(0, s.length() - 1, s, true);
    }
    int solve(int i, int j, string &s, bool iTN) {
        if (i > j) {
            // invalid
            return 0;
        }
        if (i == j) {
            return (s[i] == 'T') == iTN ? 1 : 0;
        }
        pair<int, int> key = {i, j};
        if (mp.find(key) != mp.end()) {
            return iTN ? mp[key][0] : mp[key][1];
        }
        int trueCount = 0;
        int falseCount = 0;
        for (int k = i + 1; k <= j - 1; k = k + 2)
        {

            int leftTrue = solve(i, k-1, s, true);
            int leftFalse = solve(i, k-1, s, false);
            int rightTrue = solve(k + 1, j, s, true);
            int rightFalse = solve(k + 1, j, s, false);

            switch (s[k])
            {
                case '&':
                {
                    trueCount += leftTrue * rightTrue;
                    falseCount += leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse;
                    break;
                }
                case '|':
                {
                    trueCount += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
                    falseCount += leftFalse * rightFalse;
                    break;
                }
                case '^':
                {
                    trueCount += leftTrue * rightFalse + leftFalse * rightTrue;
                    falseCount += leftTrue * rightTrue + leftFalse * rightFalse;
                    break;
                }
            }
        }
        mp[key] = {trueCount, falseCount};
        return iTN ? trueCount : falseCount;
        
    }
};
