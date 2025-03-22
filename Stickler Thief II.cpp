class Solution {
  public:
    int robLinear(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        int prev2 = 0, prev1 = 0;
        for (int num : nums) {
            int temp = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
    
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        
        vector<int> case1(arr.begin(), arr.end() - 1); 
        vector<int> case2(arr.begin() + 1, arr.end()); 
        
        return max(robLinear(case1), robLinear(case2));
    }
};
