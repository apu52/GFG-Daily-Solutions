class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<pair<int,int>>> path;

    bool dfs(int i,int j,vector<vector<int>>& mat)
    {
        int n = mat.size();

        if(i == n-1 && j == n-1)
            return true;

        if(dp[i][j] != -1)
            return dp[i][j];

        for(int jump = 1; jump <= mat[i][j]; jump++)
        {
            // Right first
            if(j + jump < n && mat[i][j + jump] != 0)
            {
                if(dfs(i, j + jump, mat))
                {
                    path[i][j] = {i, j + jump};
                    return dp[i][j] = 1;
                }
            }

            // Down second
            if(i + jump < n && mat[i + jump][j] != 0)
            {
                if(dfs(i + jump, j, mat))
                {
                    path[i][j] = {i + jump, j};
                    return dp[i][j] = 1;
                }
            }
        }

        return dp[i][j] = 0;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat)
    {
        int n = mat.size();


        dp.assign(n, vector<int>(n, -1));
        path.assign(n, vector<pair<int,int>>(n, {-1,-1}));

        // destination is always usable
        mat[n-1][n-1] = max(mat[n-1][n-1], 1);

        if(!dfs(0, 0, mat))
            return {{-1}};

        vector<vector<int>> ans(n, vector<int>(n, 0));

        int i = 0, j = 0;

        while(!(i == n-1 && j == n-1))
        {
            ans[i][j] = 1;

            auto nxt = path[i][j];
            i = nxt.first;
            j = nxt.second;
        }

        ans[n-1][n-1] = 1;

        return ans;
    }
};
