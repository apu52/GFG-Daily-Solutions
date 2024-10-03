class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) {
        int count1 = 0,count2 = 0;
        int major1 = nums[0],major2 = nums[0];
        int n = nums.size();
        
        for(int i=0;i<nums.size();i++){
            if(major1 == nums[i]){
                count1++;
            }
            else if(major2 == nums[i]){
                count2++;
            }
            else if(count1 == 0){
                major1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                major2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        vector<int> ans;
        int freq1 = 0,freq2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == major1){
                freq1++;
            }
            else if(nums[i] == major2){
                freq2++;
            }
        }
        
        if(freq1 > n/3){
            ans.push_back(major1);
        }
        if(freq2 > n/3){
            ans.push_back(major2);
        }
        
        if(ans.size() == 0){
            return {-1};
        }
        return ans;
    }
};
