class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
         vector<int> freq(26, 0);
    int left = 0, maxFreq = 0, maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        // Update frequency of current character
        freq[s[right] - 'A']++;
        
        // Update max frequency in current window
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        // If more than k replacements needed, shrink window
        while ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
        }

        // Update answer
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
    }
};
