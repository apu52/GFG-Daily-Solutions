class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Queue to store {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        int freshCount = 0;
        
        // 1. Initial scan: Find rotten oranges and count fresh ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) {
                    q.push({{i, j}, 0});
                } else if (mat[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        int maxTime = 0;
        int rottedByUs = 0;
        
        // Direction vectors for Up, Down, Left, Right
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        
        // 2. BFS traversal
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            maxTime = max(maxTime, t);
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nrow = r + dRow[i];
                int ncol = c + dCol[i];
                
                // Check boundaries and if the orange is fresh
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    mat[nrow][ncol] == 1) {
                    mat[nrow][ncol] = 2; // Mark as rotten
                    q.push({{nrow, ncol}, t + 1});
                    rottedByUs++;
                }
            }
        }
        
        // 3. Final Check
        return (rottedByUs == freshCount) ? maxTime : -1;
    }
};
