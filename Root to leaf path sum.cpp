class Solution {
  public:
  bool func(Node * root,int t,int x){
      if(root==NULL)return false;
      else if(root->left==NULL && root->right==NULL ){
          if(x+root->data==t)return true;
          return false;
      }
      bool left = func(root->left,t,x+root->data);
      bool right = func(root->right,t,x+root->data);
      return left||right;
  }
    bool hasPathSum(Node *root, int target) {
        // Your code here
        return func(root,target,0);
    }
};
