class Solution {
  public:
    // Function to return the maximum sum of non-adjacent nodes.
    map<pair<Node *,bool>,int>mp;
    int f(Node *root,bool flag){
        if(root==NULL)return 0;
        if(mp.find({root,flag})!=mp.end())return mp[{root,flag}];
        int included=0;
        if(flag)included=root->data+f(root->left,false)+f(root->right,false);
        int excluded=f(root->left,true)+f(root->right,true);
        return mp[{root,flag}]=max(included,excluded);
    }
    int getMaxSum(Node *root) {
        // code here
        return f(root,true);
    }
};
