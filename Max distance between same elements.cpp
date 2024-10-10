class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> first_occurrence; 
        int max_dist = 0; 
        
        for (int i = 0; i < arr.size(); i++) {
            if (first_occurrence.find(arr[i]) == first_occurrence.end()) {
            
                first_occurrence[arr[i]] = i;
            } else {
        
                int dist = i - first_occurrence[arr[i]];
                max_dist = max(max_dist, dist);
            }
        }
        
        return max_dist;
    }
};
