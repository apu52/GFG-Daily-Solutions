class Solution {
  public:
    int pairsum(vector<int> &arr) {
        int max1 = 0, max2 = 0;
        
        for (const auto &i: arr)  {
            if (i > max1)  {
                max2 = max1;
                max1 = i;
            }
            else if (i > max2)
                max2 = i;
        }
        
        return max1 + max2;
    }
};
