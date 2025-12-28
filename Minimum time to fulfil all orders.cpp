class Solution {
  public:
    long long donutsInTime(long long r, long long T) {
        // k = floor( (-1 + sqrt(1 + 8T/r)) / 2 )
        long double val = 1.0L + (8.0L * T) / r;
        long double k = (sqrt(val) - 1.0L) / 2.0L;
        return (long long)k;
    }

    int minTime(vector<int>& ranks, int n) {
        long long low = 0;
        long long mx = *max_element(ranks.begin(), ranks.end());
        long long high = mx * 1LL * n * (n + 1) / 2;   // safe upper bound
        
        while (low < high) {
            long long mid = (low + high) / 2;

            long long donuts = 0;
            for (long long r : ranks) {
                donuts += donutsInTime(r, mid);
                //if (donuts >= n) break;   // early stop
            }

            if (donuts >= n)
                high = mid;
            else
                low = mid + 1;
        }

        return (int)low;
    }
};
