class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        sort(arr.begin(),arr.end());
        int prev=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i][0]<prev)return false;
            prev=arr[i][1];
        }
        return true;
    }
};
