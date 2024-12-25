
class Solution {
  public:
    int findMinOperation(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> rowSum(n, 0), colSum(n, 0);

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        }

        
        int targetSum = *max_element(rowSum.begin(), rowSum.end());
        targetSum = max(targetSum, *max_element(colSum.begin(), colSum.end()));

        
        int operations = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int neededIncrement = targetSum - rowSum[i];
                mat[i][j] += neededIncrement;
                operations += neededIncrement;
                rowSum[i] += neededIncrement;
                colSum[j] += neededIncrement;
            }
        }

        return operations;
    }
};
