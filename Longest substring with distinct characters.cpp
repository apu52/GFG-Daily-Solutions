class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        vector<int> freq(26, 0);
        int cnt = 0;
        int n = s.length();
        
        int i = 0, j = 0;
        while(j < n) {
            freq[s[j] - 'a'] ++;
            
            while(freq[s[j] - 'a'] > 1) {
                freq[s[i] - 'a'] --;
                i ++;
            }
            
            cnt = max(cnt, j - i + 1);
            j ++;
        }
        
        return cnt;
    }
};
