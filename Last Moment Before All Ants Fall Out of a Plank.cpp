class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int last = 0;

        
        for (auto l : left) {
            last = max(last, l); 
        }

        
        for (auto r : right) {
            last = max(last, n - r); 
        }

        return last;
    }
};
