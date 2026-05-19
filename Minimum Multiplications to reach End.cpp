class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
    if (start == end)
            return 0;

        int mod = 1000;

        vector<int> dist(1001, INT_MAX);
        queue<int> q;

        q.push(start);
        dist[start] = 0;
        while (!q.empty()) {
            int top = q.front();
            q.pop();

            for (auto it : arr) {
                int temp = (top * it) % 1000;

                if (dist[temp] > dist[top] + 1) {
                    dist[temp] = dist[top] + 1;

                    if (temp == end)
                        return dist[temp];

                    q.push(temp);
                }
            }
        }

        return -1;
    }
};
