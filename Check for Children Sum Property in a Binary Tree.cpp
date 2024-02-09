class Solution{
public:
    
    int isSumProperty(Node *root)
    {
      
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return 1;
        
        int leftSum = 0, rightSum = 0;
         
        if (root->left != NULL)
            leftSum = root->left->data;
        
        if (root->right != NULL)
            rightSum = root->right->data;
        
       
        if ((root->data == leftSum + rightSum) && isSumProperty(root->left) && isSumProperty(root->right))
            return 1;
        else
            return 0;
    }
};
