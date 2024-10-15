class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
   
    int subArraySum(vector<int>& arr, int tar) {
        int n = arr.size();
        
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        int count = 0, currSum = 0;
        
        for(auto& num : arr){
            currSum += num;
            
            if(mp.count(currSum - tar)){
                count += mp[currSum - tar];
            }
            
            mp[currSum] += 1;
        }
        
        return count;
    }
};
