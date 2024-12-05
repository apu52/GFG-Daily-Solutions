class Solution {
  public:
    void sort012(vector<int>& arr) {
    int i = 0;
    int j = 0;
    int k = arr.size() - 1;

    while (j <= k) {
        switch (arr[j]) {
            case 0:
                swap(arr[i], arr[j]);
                ++i;
                ++j;
                break;
            case 1:
                ++j;
                break;
            case 2:
                swap(arr[j], arr[k]);
                --k;
                break;
        }
    }
}
};
