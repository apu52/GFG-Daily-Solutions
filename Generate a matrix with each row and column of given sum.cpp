class Solution {
  public:
    vector<vector<int>> generateMatrix(vector<int> rowSum, vector<int> colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        
        
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                int value = min(rowSum[i], colSum[j]);
                matrix[i][j] = value;
                
               
                rowSum[i] -= value;
                colSum[j] -= value;
            }
        }
        
        return matrix;
    }
};
