class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node* createTree(vector<int> parent) {
        int n = parent.size();
        if (n == 0) return nullptr;

        // Step 1: Create all nodes
        vector<Node*> nodes(n);
        for (int i = 0; i < n; ++i) {
            nodes[i] = new Node(i);
        }

        Node* root = nullptr;

        // Step 2: Establish parent-child relationships
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                root = nodes[i];
            } else {
                Node* parentNode = nodes[parent[i]];
                if (!parentNode->left) {
                    parentNode->left = nodes[i];
                } else {
                    parentNode->right = nodes[i];
                }
            }
        }

        return root;
    }
};
