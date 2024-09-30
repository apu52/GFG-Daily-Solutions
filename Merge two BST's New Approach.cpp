class Solution {
  public:
    // Function to perform inorder traversal and store the result in a vector.
    void inorder(Node* root, vector<int>& res) {
        if (root == nullptr)
            return;
        inorder(root->left, res);
        res.push_back(root->data);
        inorder(root->right, res);
    }

    // Function to merge two sorted arrays.
    vector<int> mergeSortedArrays(const vector<int>& list1, const vector<int>& list2) {
        vector<int> mergedList;
        int i = 0, j = 0;
        int n1 = list1.size(), n2 = list2.size();
        
        // Merging two sorted lists.
        while (i < n1 && j < n2) {
            if (list1[i] <= list2[j]) {
                mergedList.push_back(list1[i]);
                i++;
            } else {
                mergedList.push_back(list2[j]);
                j++;
            }
        }

        // Append the remaining elements.
        while (i < n1) {
            mergedList.push_back(list1[i]);
            i++;
        }
        while (j < n2) {
            mergedList.push_back(list2[j]);
            j++;
        }
        
        return mergedList;
    }

    // Function to return a list of integers denoting the node values of both the BST in a sorted order.
    vector<int> merge(Node* root1, Node* root2) {
        // Vectors to store inorder traversals of both BSTs.
        vector<int> list1, list2;
        
        // Perform inorder traversals of both trees.
        inorder(root1, list1);
        inorder(root2, list2);
        
        // Merge the two sorted lists.
        return mergeSortedArrays(list1, list2);
    }
};
