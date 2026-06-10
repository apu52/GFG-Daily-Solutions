class Solution {
  public:
    int binarySearchable(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        // {l, r, low, high}
        stack<tuple<int, int, int, int>> st;
        st.push({0, n - 1, INT_MIN, INT_MAX});

        while (!st.empty()) {
            auto [l, r, low, high] = st.top();
            st.pop();

            if (l > r) continue;

            int mid = l + (r - l) / 2;

            if (arr[mid] > low && arr[mid] < high) {
                ans++;
            }

            // Left half
            st.push({l, mid - 1, low, min(high, arr[mid])});

            // Right half
            st.push({mid + 1, r, max(low, arr[mid]), high});
        }

        return ans;
    }
};
