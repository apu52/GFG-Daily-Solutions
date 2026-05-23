class Solution {
  public:
    void toSumTree(Node *root) {
        // code here
        if(!root) return ;
        int l =0, r =0;
        if(root->left){
            l = root->left->data;
            toSumTree(root->left);
            l += root->left->data;
        }
        if(root->right){
            r = root->right->data;
            toSumTree(root->right);
            r += root->right->data;
        }
        root->data =  l+r;
        return;
    }
};
