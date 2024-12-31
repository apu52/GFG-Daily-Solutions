class Solution {
  public:
    
    int longestConsecutive(vector<int>& arr) {
        
        unordered_set<int> hst(arr.begin(), arr.end());
        int ans = 0;
        for (int i : arr) {
            int curr = 0, tmp = i, tmp2 = i - 1;
            if (hst.count(i)) {
                while (hst.count(tmp)) {
                    curr++;
                    hst.erase(tmp);
                    tmp++;
                }
                while (hst.count(tmp2)) {
                    curr++;
                    hst.erase(tmp2);
                    tmp2--;
                }
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};
