class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        vector<int> ans(arr.size(), 0);
        
        sort(arr.begin(), arr.end());
        int i = 0, j = arr.size() - 1;
        int count = 0;
        
        while (count < arr.size())  {
            if (count%2 == 0)
                ans[count++] = arr[j--];
            else
                ans[count++] = arr[i++];
        }
        
        return ans;
    }
};
