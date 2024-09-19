class Solution {
public:
    // Function to reverse a substring in a given string (in-place).
    void reverseSubstring(int start, int end, string &s) {
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseWords(string s) {
        int n = s.length();
        int start = 0;

        // Reverse each word in the string.
        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] == '.') {
                reverseSubstring(start, i - 1, s);
                start = i + 1;  // Move start to the beginning of the next word.
            }
        }

        // Reverse the entire string to get the words in the correct order.
        reverseSubstring(0, n - 1, s);

        return s;
    }
};
