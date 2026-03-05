class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int l = 0;
        int ans = -1;
        int distinctCount = 0;
        int freq[26] = {0};
        for(int r=0;r<s.length();r++){
            freq[s[r]-'a']++;
            if(freq[s[r]-'a']==1) distinctCount++;
            while(distinctCount > k){
                freq[s[l]-'a']--;
                if(freq[s[l]-'a'] == 0) distinctCount--;
                l++;
            }
            if(distinctCount == k){
                ans = max(ans, r-l+1);
            }
        }
        return ans;
    }
};
