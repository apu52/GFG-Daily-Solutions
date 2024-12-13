class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        if (arr[0] < arr[n - 1])
            return arr[0];

        int beg = 0, end = n - 1;
        while (beg <= end) {
            int mid = (beg + end) / 2;

            if (mid > 0 && arr[mid] < arr[mid - 1])
                return arr[mid];

            if (arr[beg] <= arr[mid] && arr[mid] > arr[end])
                beg = mid + 1;
            else
                end = mid - 1;
        }

        return arr[beg];
    }
};
