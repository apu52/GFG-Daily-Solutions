class Solution {
  public:
    void find(int n,int i,vector<int>&arr,vector<vector<int>>&ans){
        if(i==n-1){
            ans.push_back(arr);
            return ;
        }
        
        for(int j=i;j<n;j++){
            swap(arr[i],arr[j]);
            find(n,i+1,arr,ans);
            swap(arr[i],arr[j]);
        }
        return ;
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> ans;
        find(n,0,arr,ans);
        return ans;
        
        
    }
};
