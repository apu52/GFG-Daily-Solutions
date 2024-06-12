class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int cnt=0;
        for(int i=1;i<=n;i++){
            int temp=i;
            while(temp>0){
                int rem=temp%10;
                if(rem==4) {cnt++;break;}
                temp/=10;
                
            }
        }
        return cnt;
    }
};
