class Solution {
  public:
    vector<vector<int>> spiralFill(int n, int m, vector<int> &arr) {
        vector<vector<int>> matrix(n, vector<int>(m, 0));

        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        int index = 0; 

        while (top <= bottom && left <= right) {
            
            for (int j = left; j <= right && index < arr.size(); j++) {
                matrix[top][j] = arr[index++];
            }
            top++;

            
            for (int i = top; i <= bottom && index < arr.size(); i++) {
                matrix[i][right] = arr[index++];
            }
            right--;

            
            for (int j = right; j >= left && index < arr.size(); j--) {
                matrix[bottom][j] = arr[index++];
            }
            bottom--;

            
            for (int i = bottom; i >= top && index < arr.size(); i--) {
                matrix[i][left] = arr[index++];
            }
            left++;
        }

        return matrix;
    }
};
