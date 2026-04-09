class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        
        vector<int> ans;
        
        int m = a.size();
        int n = b.size();
        int i = 0;
        int j = 0;
        
        while (i < m &&  j < n) {
            
            if (a[i] == b[j]) {
                if (ans.empty()) {
                    ans.push_back(a[i]);
                } else if (ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }
                i++;
                j++;
            } else if (a[i] > b[j]) {
                j++;
            } else {
                i++;
            }
        }
        
        return ans;
    }
};
