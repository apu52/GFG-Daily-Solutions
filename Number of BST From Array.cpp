class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        
        // Compute Catalan numbers up to n
        vector<int> catalan(n + 1, 0);
        catalan[0] = 1;
        catalan[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - 1 - j];
            }
        }
        
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            int leftCount = 0, rightCount = 0;
            
            for (int j = 0; j < n; j++) {
                if (arr[j] < arr[i]) leftCount++;
                else if (arr[j] > arr[i]) rightCount++;
            }
            
            ans.push_back(catalan[leftCount] * catalan[rightCount]);
        }
        
        return ans;
    }
};
