class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int ans = arr[0];
        int count = 0;
        for(int i = 0; i < arr.size(); i++){
            if(count == 0){
                ans = arr[i];
            }
            if(arr[i] == ans){
                count++;
            }
            else if(arr[i] != ans){
                count--;
            }
        }
        count = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == ans) {
                count++;
            }
        }
    
        if(count > arr.size() / 2)
            return ans;
        else
            return -1;
        }
};
