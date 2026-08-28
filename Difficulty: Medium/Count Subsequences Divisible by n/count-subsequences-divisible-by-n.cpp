
class Solution {
  public:

    const int MOD = 1e9 + 7;

    int solve(string &s, int index, int rem, int n,
              vector<vector<int>> &dp) {

        // All characters processed
        if (index == s.size()) {
            return (rem == 0);
        }

        if (dp[index][rem + 1] != -1)
            return dp[index][rem + 1];

        int digit = s[index] - '0';

        // Don't take current digit
        int notTake = solve(
            s, index + 1, rem, n, dp
        );

        // Take current digit
        int newRem;

        if (rem == -1) {
            // Starting a new subsequence
            newRem = digit % n;
        }
        else {
            // Appending digit
            newRem = (rem * 10 + digit) % n;
        }

        int take = solve(
            s, index + 1, newRem, n, dp
        );

        return dp[index][rem + 1] =
            (take + notTake) % MOD;
    }

    int countSubsequences(string& s, int n) {

        int len = s.size();

        // rem = -1 ... n-1
        // Hence n+1 possible states
        vector<vector<int>> dp(
            len, vector<int>(n + 1, -1)
        );

        return solve(s, 0, -1, n, dp);
    }
};

