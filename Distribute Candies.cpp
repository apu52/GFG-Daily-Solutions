class Solution {
public:
    int moves = 0;
    
    int dfs(Node* root) {
        if (!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        // Count moves from left and right
        moves += abs(left) + abs(right);
        
        // Return excess candies
        return root->data + left + right - 1;
    }
    
    int distCandy(Node* root) {
        dfs(root);
        return moves;
    }
};
