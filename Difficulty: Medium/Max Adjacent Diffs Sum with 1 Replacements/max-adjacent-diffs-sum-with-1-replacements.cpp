class Solution {
    int dp[100005][2];

    int f(int idx, bool flag, vector<int>& arr){
        if(idx == arr.size()) return 0;

        if(dp[idx][flag] != -1) return dp[idx][flag];

        int ans1 = INT_MIN;
        int ans2 = INT_MIN;

        if(idx == 0) {
            ans1 = f(idx + 1, false, arr);
            ans2 = f(idx + 1, true, arr);
        } else{
            int prevVal = flag ? 1 : arr[idx - 1];

            ans1 = abs(arr[idx] - prevVal) + f(idx + 1, false, arr);
            ans2 = abs(1 - prevVal) + f(idx + 1, true, arr);
        }

        return dp[idx][flag] = max(ans1, ans2);
    }
  public:
    int maxDiffSum(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        int ans = f(0, false, arr);
        return ans;
    }
};