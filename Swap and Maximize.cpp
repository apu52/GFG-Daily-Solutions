class Solution {
public:
    long long maxSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> rearranged(n);
        
        int left = 0, right = n - 1;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                rearranged[i] = arr[right--];
            } else {
                rearranged[i] = arr[left++];
            }
        }

        long long maxSum = 0;
        for (int i = 0; i < n; ++i) {
            maxSum += abs(rearranged[i] - rearranged[(i + 1) % n]);
        }

        return maxSum;
    }
};
