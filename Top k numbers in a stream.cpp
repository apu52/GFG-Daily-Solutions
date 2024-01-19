class Solution { 
  public: 
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) { 
   
        vector<int> top(K + 1); 
        vector<vector<int>> ans; 
        unordered_map<int, int> m; 
     
        for (int i = 0; i < N; i++) { 
             
            vector<int>temp; 
            m[arr[i]]++; 
            top[K] = arr[i]; 
            auto it = find(top.begin(), top.end() - 1, arr[i]); 
            for (int j = distance(top.begin(), it) - 1; j >= 0; --j) { 
                if (m[top[j]] < m[top[j + 1]]) 
                    swap(top[j], top[j + 1]); 
                else if ((m[top[j]] == m[top[j + 1]]) && (top[j] > top[j+1])) 
                    swap(top[j], top[j + 1]); 
                else 
                    break; 
            } 
            for (int i = 0; i < K && top[i] != 0; ++i) 
                temp.push_back(top[i]); 
            ans.push_back(temp); 
        } 
        return ans; 
    } 
};
