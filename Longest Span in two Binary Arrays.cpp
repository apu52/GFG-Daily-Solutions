class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
      int n = a1.size();
        
        
        vector<int> first_occurrence(2 * n + 1, -2);
        
        int max_len = 0;
        int prefix_sum = 0;
        
        
        first_occurrence[0 + n] = -1;
        
        for (int i = 0; i < n; i++) {
            
            prefix_sum += (a1[i] - a2[i]);
            
            
            int target_index = prefix_sum + n;
            
            
            if (first_occurrence[target_index] != -2) {
                
                int current_len = i - first_occurrence[target_index];
                max_len = max(max_len, current_len);
            } else {
                
                first_occurrence[target_index] = i;
            }
        }
        
        return max_len;
        
    }
};
