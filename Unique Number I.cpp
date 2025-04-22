class Solution {
  public:
    int findUnique(vector<int> &arr) {
        int ans=0;
        for(int num:arr) {
            ans^=num;
        }
        return ans;
    }
};
