class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        int idx=upper_bound(arr.begin(),arr.end(),k)-arr.begin()-1;
        if(idx>=0) {
            if(arr[idx]==k)
                return idx;
            return idx+1;
        }
        return 0;
    }
};
