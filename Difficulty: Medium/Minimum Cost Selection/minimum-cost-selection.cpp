class Solution {
    int f(int idx, vector<vector<int>>& mat, int prev,
          vector<vector<int>>& dp) {

        if(idx == mat.size())
            return 0;

        if(dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int mini = INT_MAX;

        for(int col = 0; col < 3; col++) {

            if(col == prev)
                continue;

            int ans = mat[idx][col] +
                      f(idx + 1, mat, col, dp);

            mini = min(mini, ans);
        }

        return dp[idx][prev + 1] = mini;
    }

public:
    int minCost(vector<vector<int>>& mat) {

        int n = mat.size();

        
        vector<vector<int>> dp(n, vector<int>(4, -1));

        return f(0, mat, -1, dp);
    }
};