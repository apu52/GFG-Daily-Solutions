class Solution {
  public:
    long long findNth(long long n) {
        // code here.
        long long result=0;
        long long mult=1;
        while(n){
            result+= (mult)*(n%9);
            mult= mult*10;
            n=n/9;
        }
        
        return result;
    }
};
