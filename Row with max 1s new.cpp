class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        unordered_map<int,int>ans;
        int maxi=-1;
        int ind=-1;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                if(arr[i][j]==1){
                    ans[i]++;
                    if(maxi<ans[i]){
                        maxi=ans[i];
                        ind=i;
                    }
                }
            }
        }
        return ind;
        
    }
};
