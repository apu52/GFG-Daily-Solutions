class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        // Step 1: Create a graph
        vector<unordered_set<int>> graph(K);
        vector<int> inDegree(K, 0);
        
        // Step 2: Build the graph
        for (int i = 0; i < N - 1; ++i) {
            string word1 = dict[i];
            string word2 = dict[i + 1];
            for (int j = 0; j < min(word1.size(), word2.size()); ++j) {
                if (word1[j] != word2[j]) {
                    if (graph[word1[j] - 'a'].find(word2[j] - 'a') == graph[word1[j] - 'a'].end()) {
                        graph[word1[j] - 'a'].insert(word2[j] - 'a');
                        inDegree[word2[j] - 'a']++;
                    }
                    break;
                }
            }
        }
        
        // Step 3: Topological Sort using Kahn's Algorithm
        queue<int> q;
        for (int i = 0; i < K; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        string order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order += (char)(u + 'a');
            for (int v : graph[u]) {
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // If the order contains all characters, return it
        return order.size() == K ? order : "";
    }
};
