class Solution {
public:
    vector<string> camelCase(vector<string> &arr, string &pat) {
        vector<string> result;

        for (const string &word : arr) {
            string caps = "";

            
            for (char ch : word) {
                if (isupper(ch)) {
                    caps += ch;
                }
            }

            
            if (caps.find(pat) == 0) {
                result.push_back(word);
            }
        }

        return result;
    }
};
