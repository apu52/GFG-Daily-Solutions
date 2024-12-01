class Solution {
  private:
    vector<int> computeLPS(string& pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        int len = 0, i = 1;
        
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    
  public:
    vector<int> search(string& pat, string& txt) {
        vector<int> result;
        int n = txt.size();
        int m = pat.size();
        
        vector<int> lps = computeLPS(pat);
        int i = 0, j = 0;
        
        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }
            
            if (j == m) {
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && txt[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return result;
    }
};
