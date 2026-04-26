class Solution {
public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();

        vector<bool> visited(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        pq.push({0, 0}); // {cost, node}
        int totalCost = 0;

        while(!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if(visited[u]) continue;

            visited[u] = true;
            totalCost += cost;

            for(int v = 0; v < n; v++) {
                if(!visited[v]) {
                    int dist = abs(houses[u][0] - houses[v][0]) +
                               abs(houses[u][1] - houses[v][1]);

                    pq.push({dist, v});
                }
            }
        }

        return totalCost;
    }
};
