class Solution 
{ 
    vector<vector<int>> res; 
    vector<int> ds; 
    public: 
    void preorder(Node* root,int sum){ 
        if(!root) return; 
         
        sum -= root->key; 
        ds.push_back(root->key); 
        if(sum == 0){ 
            res.push_back(ds); 
        } 
         
        preorder(root->left,sum); 
        preorder(root->right,sum); 
         
        ds.pop_back(); 
    } 
    vector<vector<int>> printPaths(Node *root, int sum) 
    { 
        preorder(root,sum); 
        return res; 
    } 
};
