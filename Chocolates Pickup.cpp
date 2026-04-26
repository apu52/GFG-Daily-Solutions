class Solution {
public:
    int maxChocolate(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // dp[j1][j2] = max chocolates from current row
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // Base case: last row
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    dp[j1][j2] = grid[n-1][j1];
                else
                    dp[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        // Fill from bottom to top
        for (int i = n - 2; i >= 0; i--) {
            vector<vector<int>> curr(m, vector<int>(m, 0));

            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {

                    int maxi = 0;

                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {

                            int nj1 = j1 + d1;
                            int nj2 = j2 + d2;

                            if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {

                                int value;
                                if (j1 == j2)
                                    value = grid[i][j1];
                                else
                                    value = grid[i][j1] + grid[i][j2];

                                value += dp[nj1][nj2];
                                maxi = max(maxi, value);
                            }
                        }
                    }

                    curr[j1][j2] = maxi;
                }
            }

            dp = curr;
        }

        // Start positions: (0,0) and (0,m-1)
        return dp[0][m-1];
    }
};
