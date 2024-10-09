class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        Node* ans[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                Node* newnode=new Node(mat[i][j]);
                ans[i][j]=newnode;
                if(j>0){
                    ans[i][j-1]->right=ans[i][j];
                }
                if(i>0){
                    ans[i-1][j]->down=ans[i][j];
                }
            }
        }
        return ans[0][0];
    }
};
