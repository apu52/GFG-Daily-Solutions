class Solution {
public:
    bool sentencePalindrome(string &s) {
        string cleaned = "";
        
        // Clean the input: retain only alphanumeric characters and convert to lowercase
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }

        // Check if the cleaned string is a palindrome
        int left = 0, right = cleaned.size() - 1;
        while (left < right) {
            if (cleaned[left] != cleaned[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
