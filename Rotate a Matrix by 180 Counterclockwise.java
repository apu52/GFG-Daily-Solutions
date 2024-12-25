class Solution {
    public void rotateMatrix(int[][] mat) {
        int n = mat.length;
        
       
        if(n == 1) return;
        
        
        int left = 0, right = n*n - 1;
        
        while(left < right) {
            
            int r1 = left/n, c1 = left%n;
            int r2 = right/n, c2 = right%n;
            
            
            int temp = mat[r1][c1];
            mat[r1][c1] = mat[r2][c2];
            mat[r2][c2] = temp;
            
            left++;
            right--;
        }
    }
}
