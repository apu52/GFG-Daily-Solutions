void rotate(vector<vector<int> >& matrix) {
        
        int n=matrix.size();
        
        //transpose
        for( int i = 0 ; i < n; i++ )
        {
            for( int j = i ; j < n ; j++ )
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        
        //change place of ROW
        
        for(int j=0 ; j<n/2 ; j++)
        {
            for(int i=0 ; i < n ; i++ )
            {
                int temp= matrix[i][j];
                matrix[i][j] = matrix[i][n-1-j];
                matrix[i][n-1-j]=temp;   
            }
        }
        
        
}
