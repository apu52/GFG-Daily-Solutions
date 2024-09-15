class Solution {
  public:
    Node *head = nullptr, *prev = nullptr;
    
    // Function to convert binary tree to doubly linked list and return the head.
    Node* bToDLL(Node* root) {
        bToDLLUtil(root);
        return head;
    }
    
    // Utility function to perform in-order traversal and link nodes.
    void bToDLLUtil(Node* root) {
        if (root == nullptr) {
            return;
        }
    
        // Recur on the left subtree.
        bToDLLUtil(root->left);
    
        // If head is null, this is the first node.
        if (head == nullptr) {
            head = prev = root;
        } else {
            // Link the previous node with the current node.
            prev->right = root;
            root->left = prev;
            prev = root;
        }
    
        // Recur on the right subtree.
        bToDLLUtil(root->right);
    }
};
