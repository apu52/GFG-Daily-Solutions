class Solution {
public:
    bool canAchieve(vector<int>& arr, int k, int w, long long target) {
        int n = arr.size();
        vector<long long> added(n, 0);

        long long totalDays = 0;
        long long currAdd = 0;

        for (int i = 0; i < n; i++) {
            if (i >= w)
                currAdd -= added[i - w];

            long long currentHeight = arr[i] + currAdd;

            if (currentHeight < target) {
                long long need = target - currentHeight;
                totalDays += need;

                if (totalDays > k)
                    return false;

                currAdd += need;
                added[i] = need;
            }
        }
        return true;
    }

    long long maxMinHeight(vector<int>& arr, int k, int w) {
        long long low = *min_element(arr.begin(), arr.end());
        long long high = low + k;
        long long ans = low;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canAchieve(arr, k, w, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
