class Solution{ 
public: 
    string matrixChainOrder(int p[], int n){ 
         
        vector<vector<int>> dp(n, vector<int>(n, 0)); 
        vector<vector<int>> bracket(n, vector<int>(n, 0)); 
         
        for (int len = 2; len < n; len++) { 
            for (int i = 1; i < n - len + 1; i++) { 
                int j = i + len - 1; 
                dp[i][j] = INT_MAX; 
                 
                for (int k = i; k <= j - 1; k++) { 
                    int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]; 
                     
                    if (cost < dp[i][j]) { 
                        dp[i][j] = cost; 
                        bracket[i][j] = k; 
                    } 
                } 
            } 
        } 
         
        return printParenthesis(bracket, 1, n - 1); 
    } 
 
private: 
    string printParenthesis(const vector<vector<int>>& bracket, int i, int j) { 
        if (i == j) { 
            return string(1, 'A' + i - 1); 
        } 
 
        return "(" + printParenthesis(bracket, i, bracket[i][j]) + 
               printParenthesis(bracket, bracket[i][j] + 1, j) + ")"; 
    } 
};
