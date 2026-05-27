class Solution {
public:
    bool wifiRange(string& s, int x) {
        int range = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                range = x;
            else {
                if (range)
                    range--;
                else {
                    int j = i;
                    while (j < s.size() && s[j] == '0')
                        j++;
                    if (j == s.size() || j - i > x)
                        return false;
                    i = j;
                    range = x;
                }
            }
        }
        return true;
    }
};
