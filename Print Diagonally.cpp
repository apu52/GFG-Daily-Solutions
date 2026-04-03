class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        int n=mat.size(), m=mat[0].size();
        vector<int> res;
        for(int y=0;y<m;y++)
        {
            int i=0, j=y;
            while(i<n and j>=0)
            {
                res.push_back(mat[i][j]);
                i++,j--;
            }
        }
        for(int x=1;x<n;x++)
        {
            int i = x, j = m-1;
            while(i<n and j>=0)
            {
                res.push_back(mat[i][j]);
                i++,j--;
            }
        }
        return res;
    }
};
