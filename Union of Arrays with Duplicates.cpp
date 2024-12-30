class Solution {
  public:
    
    int findUnion(vector<int>& a, vector<int>& b) {
       
        unordered_set<int> hst;
        for (int i : a) {
            hst.insert(i);
        }
        for (int i : b) {
            hst.insert(i);
        }
        return hst.size();
    }
};
