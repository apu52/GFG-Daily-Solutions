class Solution {
  public:
    bool palindromePair(vector<string>& arr) {
        // Store each string with its index
        unordered_map<string, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }

        for (int i = 0; i < arr.size(); i++) {
            string s = arr[i];
            int n = s.size();

            // Try all possible splits
            for (int j = 0; j <= n; j++) {
                string left = s.substr(0, j);
                string right = s.substr(j);

                // Case 1: left is palindrome
                // Need reverse(right) to be placed before s
                if (isPalindrome(left)) {
                    string rev = right;
                    reverse(rev.begin(), rev.end());

                    if (mp.count(rev) && mp[rev] != i) {
                        return true;
                    }
                }

                // Case 2: right is palindrome
                // Need reverse(left) to be placed after s
                // j != n avoids duplicate check when right is empty
                if (j != n && isPalindrome(right)) {
                    string rev = left;
                    reverse(rev.begin(), rev.end());

                    if (mp.count(rev) && mp[rev] != i) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

  private:
    bool isPalindrome(const string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};
