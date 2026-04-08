class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i=0;
        for(int j=0; j<n; j++){
            if(arr[j]==0){
                swap(arr[i],arr[j]);
                i++;
            }
        }
        
    }
};
