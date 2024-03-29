class Solution {
public:
    int findShortestPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size(), d[4] = {1, -1, 0, 0};
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!mat[i][j]) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + d[k], y = j + d[3 - k];
                        if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1)
                            mat[x][y] = 2;
                    }
                }
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++)
            if (mat[i][0] == 1)
                mat[i][0] = 2, q.push({i, 0});
        
        int ans = 1;
        
        while (!q.empty()) {
            int s = q.size(), i, j;
            while (s--) {
                tie(i, j) = q.front();
                q.pop();
                if (j == m - 1)
                    return ans;
                for (int k = 0; k < 4; k++) {
                    int x = i + d[k], y = j + d[3 - k];
                    if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1)
                        mat[x][y] = 2, q.push({x, y});
                }
            }
            ans++;
        }
        return -1;
    }
};
