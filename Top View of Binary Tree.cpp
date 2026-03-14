class Solution {
  public:
    vector<int> topView(Node *root) {
        
        map <int, int> mp;
        vector<int> ans;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int col = it.second;
            
            if(!mp.count(col))
                mp[col] = node->data;
            
            if(node->left)
                q.push({node->left, col - 1});
            
            if(node->right)
                q.push({node->right, col + 1});
        }
        
        for(auto it: mp)
            ans.push_back(it.second);
        
        return ans;
    }
};
