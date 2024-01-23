class Solution {  
public:  
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {  
        vector<int> result;  
        vector<int> inDegree(n, 0);  
        vector<vector<int>> graph(n, vector<int>());  
          
        for (auto prerequisite : prerequisites) {  
            graph[prerequisite[1]].push_back(prerequisite[0]);  
            inDegree[prerequisite[0]]++;  
        }  
          
        queue<int> q;  
        for (int i = 0; i < n; i++) {  
            if (inDegree[i] == 0) {  
                q.push(i);  
            }  
        }  
          
        while (!q.empty()) {  
            int current = q.front();  
            q.pop();  
            result.push_back(current);  
            for (int neighbor : graph[current]) {  
                inDegree[neighbor]--;  
                if (inDegree[neighbor] == 0) {  
                    q.push(neighbor);  
                }  
            }  
        }  
          
        if (result.size() != n) {  
            return vector<int>();  
        }  
          
        return result;  
    }  
};
