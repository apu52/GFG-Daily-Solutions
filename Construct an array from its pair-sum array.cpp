class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        int n = arr.size();
        int m = -1;
        for(int i=1; i<=1000; i++)
        {
            if((i*(i-1)/2) == n)
            {
                m = i;
                break;
            }
        }
        int a = (arr[0] + arr[1] - arr[m-1])/2;
        vector<int> ans(m);
        ans[0] = a;
        int i = 0;
        while(i < m-1)
        {
            ans[i+1] = arr[i] - ans[0];
            i++;
        }
        return ans;
    }
};
