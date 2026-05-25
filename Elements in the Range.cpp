class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        
        for(int i = start; i <= end; i++) {
            if(s.find(i) == s.end()) {
                return false;
            }
        }
        
        return true;
    }
};
