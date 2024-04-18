class Solution {
  public:
  vector<int> twoRepeated (int arr[], int n) {
        vector<int> ans;
        for(int i=0; i<n+2; i++){
            int ind = abs(arr[i]);
            if(arr[ind]>0){
                arr[ind] = -arr[ind];
            }
            else{
                ans.push_back(ind);
            }
        }
        return ans;
  }
};
