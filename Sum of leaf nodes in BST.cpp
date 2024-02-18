class Solution { 
public: 
    int sumOfLeafNodes(Node* root) { 
        if (root == nullptr) { 
            return 0; 
        } 
         
        if (root->left == nullptr && root->right == nullptr) { 
            return root->data; 
        } 
         
        return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right); 
    } 
};
