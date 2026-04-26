class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build graph: y -> x
        for (auto &p : prerequisites) {
            int x = p[0];
            int y = p[1];
            adj[y].push_back(x);
            indegree[x]++;
        }

        queue<int> q;

        // Push all courses with no prerequisites
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int next : adj[node]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return count == n;
    }
};
