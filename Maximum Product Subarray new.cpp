class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n =arr.size();
        
        int ans = arr[0];
        int maxAns = ans, minAns = ans;
        
        for(int i=1; i<n; i++){
            if(arr[i] < 0)
                swap(maxAns, minAns);
                
            maxAns = max(arr[i], maxAns*arr[i]);
            minAns = min(arr[i], minAns*arr[i]);
            
            ans = max(ans, maxAns);
        }
        
        return ans;
    }
};
