class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return ans;
    }

    int prefixStrings(int n) {
        // C(n) = (2n)! / (n! * n! * (n + 1))

        vector<long long> fact(2 * n + 1);

        fact[0] = 1;

        for (int i = 1; i <= 2 * n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        long long numerator = fact[2 * n];

        long long denominator =
            fact[n] * fact[n] % MOD;

        // Modular inverse of denominator
        denominator = power(denominator, MOD - 2);

        long long ans = numerator * denominator % MOD;

        // Divide by (n + 1)
        ans = ans * power(n + 1, MOD - 2) % MOD;

        return ans;
    }
};