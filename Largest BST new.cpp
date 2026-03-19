class Solution {
public:
    int ans = 0;

    struct Info {
        bool isBST;
        int size;
        int minVal;
        int maxVal;
    };

    Info solve(Node* root) {
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        Info curr;

        if (left.isBST && right.isBST &&
            left.maxVal < root->data &&
            root->data < right.minVal) {

            curr.isBST = true;
            curr.size = left.size + right.size + 1;
            curr.minVal = min(root->data, left.minVal);
            curr.maxVal = max(root->data, right.maxVal);

            ans = max(ans, curr.size);
        } else {
            curr.isBST = false;
            curr.size = 0;
            curr.minVal = INT_MIN;
            curr.maxVal = INT_MAX;
        }

        return curr;
    }

    int largestBst(Node* root) {
        solve(root);
        return ans;
    }
};
