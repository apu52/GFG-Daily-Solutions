class Solution {
  public:
    // Function returns the second
    // largest elements
   
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int maxi = -1;
        int maxi2 = -1;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            int x = arr[i];
            if (x > maxi) {
                maxi2 = maxi;
                maxi = x;
            }
            else if (x > maxi2 and x < maxi)
                maxi2 = x;
        }
        
        return maxi2;
    }
};
