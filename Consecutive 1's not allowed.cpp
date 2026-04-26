class Solution {
  public:
    int countStrings(int n) {
        vector <int> arr = {2,3};
        for(int i=2;i<n;i++){
            arr.push_back(arr[i-1]+arr[i-2]);
        }
        return arr[n-1];
    }
};
