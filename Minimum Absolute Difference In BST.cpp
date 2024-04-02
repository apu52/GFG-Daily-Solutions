class Solution
{
    public:
    void inorder(Node *root, vector<int> &v){
        if(!root)
          return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    
    int absolute_diff(Node *root)
    {
        int minDiff= INT_MAX;
        vector <int> v;
        inorder(root,v);
        for(int i=1;i<v.size();i++){
            int diff=v[i]-v[i-1];
            minDiff=min(minDiff,diff);
        }
        return minDiff;
    }
};
