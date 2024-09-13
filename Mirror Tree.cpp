class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(node == NULL)
            return;
        
        //Invert the pointers    
        Node* left = node->left;
        node->left = node->right;
        node->right = left;
        
        //Do the same for both sub tree's
        mirror(node->left);
        mirror(node->right);
    }
};
