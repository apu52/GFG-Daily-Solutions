class Solution {
    long max_sum(int a[], int n) {
        long sum = 0, cur = 0, ans = 0;
        for (int i = 0; i < n; i++)     sum += a[i];
        for (int i = 0; i < n; i++)     cur += (long)i * a[i];
        
        ans = cur;

        for (int i = 1; i < n; i++) {
            long temp = cur - (sum - a[i - 1]) + (long)a[i - 1] * (n - 1);

            ans = Math.max(ans,temp);
            cur = temp;
        }
        
        return ans;
    }
}
