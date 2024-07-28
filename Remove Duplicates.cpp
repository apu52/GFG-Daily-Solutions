class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        string ans;
        for (auto i : str) {
            if (ans.find(i) != std::string::npos) {
                continue;
            }
            ans += i;
        }
        
        return ans;
    }
};
