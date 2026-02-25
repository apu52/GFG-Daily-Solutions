#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int prefixSum = 0;
        int maxLen = 0;

        unordered_map<int, int> hm;
        hm[0] = -1;

        for (int i = 0; i < n; i++) {
            prefixSum += (arr[i] > k) ? 1 : -1;

            if (prefixSum > 0)
                maxLen = i + 1;

            if (hm.find(prefixSum - 1) != hm.end())
                maxLen = max(maxLen, i - hm[prefixSum - 1]);

            if (hm.find(prefixSum) == hm.end())
                hm[prefixSum] = i;
        }

        return maxLen;
    }
};
