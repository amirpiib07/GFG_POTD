class Solution {
    int dp[101][101][101];
    vector<int> arr;

    int f(int idx, int inc, int dec) {
        if (idx == arr.size())
            return 0;

        int &ans = dp[idx][inc][dec];

        if (ans != -1)
            return ans;

        
        ans = f(idx + 1, inc, dec);

        
        if (inc == 0 || arr[idx] > inc) {
            ans = max(ans,
                      1 + f(idx + 1, arr[idx], dec));
        }

        
        if (dec == 0 || arr[idx] < dec) {
            ans = max(ans,
                      1 + f(idx + 1, inc, arr[idx]));
        }

        return ans;
    }

public:
    int minCount(vector<int>& arr) {
        this->arr = arr;

        memset(dp, -1, sizeof(dp));

        int n = arr.size();

        int selected = f(0, 0, 0);

        return n - selected;
    }
};