class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
    Node* pre = NULL;
    Node* suc = NULL;
    Node* curr = root;

    while (curr != NULL) {
        if (curr->data == key) {
            // Find predecessor: Max value in the left subtree
            if (curr->left != NULL) {
                Node* temp = curr->left;
                while (temp->right) temp = temp->right;
                pre = temp;
            }
            // Find successor: Min value in the right subtree
            if (curr->right != NULL) {
                Node* temp = curr->right;
                while (temp->left) temp = temp->left;
                suc = temp;
            }
            break; 
        } 
        else if (curr->data > key) {
            // Current node is larger than key, so it could be the successor
            suc = curr;
            curr = curr->left;
        } 
        else {
            // Current node is smaller than key, so it could be the predecessor
            pre = curr;
            curr = curr->right;
        }
    }

    return {pre, suc};
}

};
