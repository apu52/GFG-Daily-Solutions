class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        int ans=0;
        unordered_map<int,int> mm;
        for(int x:arr){
            if(mm[target-x])ans+=mm[target-x];
            mm[x]++;
        }
        return ans;
    }
};
