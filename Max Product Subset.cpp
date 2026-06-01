class Solution {
public:
    int findMaxProduct(vector<int>& arr) {
        const long long MOD = 1000000007;

        int n = arr.size();

        if (n == 1)
            return arr[0];

        int negCount = 0, zeroCount = 0;
        int maxNegative = INT_MIN;

        for (int x : arr) {
            if (x == 0)
                zeroCount++;
            else if (x < 0) {
                negCount++;
                maxNegative = max(maxNegative, x);
            }
        }

        // All zeros
        if (zeroCount == n)
            return 0;

        // Only one negative and rest zeros
        if (negCount == 1 && negCount + zeroCount == n)
            return 0;

        long long product = 1;

        for (int x : arr) {
            if (x == 0)
                continue;

            // Skip the negative closest to zero if negatives are odd
            if ((negCount & 1) && x == maxNegative) {
                negCount--;
                continue;
            }

            product = (product * ((x % MOD + MOD) % MOD)) % MOD;
        }

        return (int)product;
    }
};
