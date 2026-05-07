class Solution {
  public:
    void inorder(Node*root,vector<int>&nums)
    {
        if(!root) return ;
        inorder(root->left,nums);
        nums.push_back(root->data);
        inorder(root->right,nums);
    }
    bool isSubTree(Node *root1, Node *root2) 
    {
        vector<int>temp1;
        vector<int>temp2;
        inorder(root1,temp1);
        inorder(root2,temp2);
        int m=temp1.size();
        int n=temp2.size();
        for(int i=0;i<=m-n;i++)
        {
            int j=0;
            while(j<n && temp2[j]==temp1[i+j]) j++;
            if(j==n) return true;
        }
        return false;
    }
};
