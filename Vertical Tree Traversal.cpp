class Solution {
public:
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        map<int, vector<int>> mp; // HD -> nodes
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int hd = it.second;
            
            mp[hd].push_back(node->data);
            
            if(node->left)
                q.push({node->left, hd - 1});
                
            if(node->right)
                q.push({node->right, hd + 1});
        }
        
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
