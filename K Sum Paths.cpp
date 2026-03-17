class Solution {
  public:
    int countPathsUtil(Node* node, int k, int currSum, 
                     unordered_map<int, int>& prefSums) {
  
    if (node == nullptr)
        return 0;
  
   int pathCount = 0;
    currSum += node->data;
    
    if (currSum == k)
        pathCount++;
   
 // The count of (curr_sum − k) gives the number 
    // of paths with sum k up to the current node
    pathCount += prefSums[currSum - k];
  
   // Add the current sum into the hashmap
    prefSums[currSum]++;

    pathCount += countPathsUtil(node->left, k, currSum, prefSums);
    pathCount += countPathsUtil(node->right, k, currSum, prefSums);

    // Remove the current sum from the hashmap
    prefSums[currSum]--;
  
   return pathCount;
}

int countAllPaths(Node* root, int k) {
    unordered_map<int, int> prefSums;

    return countPathsUtil(root, k, 0, prefSums);
}

};
