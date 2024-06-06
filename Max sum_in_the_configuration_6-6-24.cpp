class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long sum=0,calc=0;
        for(int i=0;i<n;i++){
            sum+=(long)a[i];
            calc+=(long)a[i]*i;
        }
        long long maxval=calc;
        for (int i = 0; i < n; i++) {
            calc = calc + (sum - n*(long)a[n-1-i] );            
            maxval = max(calc, maxval);
        }
        return maxval;
    }
};