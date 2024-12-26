class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_map<int ,int>mp;
        for(auto num : arr){
            int left = target - num;
            if(mp.count(left)) return true;
            mp[num] = 1;
        }
        return false;
    }
};
