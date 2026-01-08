class Solution {
  public:
  int solve(vector<int>& arr, int k)
{
    int l = 0, oc = 0, ans = 0, n = arr.size();

    for (int r = 0; r < n; r++)
    {
        if (arr[r] % 2) oc++;

        while (oc > k)
        {
            if (arr[l] % 2) oc--;
            l++;
        }

        ans += (r - l + 1);
    }

    return ans;
}


    int countSubarrays(vector<int>& arr, int k) {
        return solve(arr,k)-solve(arr,k-1);
        
    }
};
