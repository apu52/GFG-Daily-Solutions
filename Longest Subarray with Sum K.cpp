class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
    long long sum = 0;
    map<int, int> mp;
    int l = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

       
        if (sum == k) {
            l = max(l, i + 1);
        }

        
        if (mp.find(sum - k) != mp.end()) {
            l = max(l, i - mp[sum - k]);
        }

        
        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    return l;
}

};
