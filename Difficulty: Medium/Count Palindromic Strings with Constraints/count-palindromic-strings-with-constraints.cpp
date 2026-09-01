class Solution {
    long long mod = 1e9 + 7;

public:
    int palindromicStrings(int n, int k) {
        long long ans = k;
        long long ways = 1;

        for (int m = 1; 2 * m <= n; m++) {
            if (m > k)
                break;

            ways = (ways * (k - m + 1)) % mod;
            ans = (ans + ways) % mod;

            if (2 * m + 1 <= n) {
                long long odd = (ways * (k - m)) % mod;
                ans = (ans + odd) % mod;
            }
        }

        return ans;
    }
};