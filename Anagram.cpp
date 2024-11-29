class Solution {
  public:
    
    bool areAnagrams(string& s1, string& s2) {
        
        if (s1.size() != s2.size()) {
            return false;
        }

        
        vector<int> freq(26, 0);

        
        for (int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }

        
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};
