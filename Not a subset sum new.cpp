class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        sort(arr.begin(), arr.end());

        long long res = 1;

        for (int num : arr) {
            if (num > res)
                break;

            res += num;
        }

        return res;
    }
};
