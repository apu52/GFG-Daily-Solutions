class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        int n=arr.size(),ans=0;
        for(int i=0;i<32;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if((1<<i)&arr[j]){
                    c++;
                }
            }
            if(c%3==1){
                ans=ans|(1<<i);
            }
        }
        return ans;
    }
};
