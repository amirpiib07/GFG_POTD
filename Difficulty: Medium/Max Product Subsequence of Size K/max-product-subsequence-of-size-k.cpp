class Solution {
public:
    int maxProduct(vector<int> &arr, int k) {
        int n = arr.size();
        const long long NEG_INF = LLONG_MIN / 2;
        const long long POS_INF = LLONG_MAX / 2;

        vector<long long> dpMax(k + 1, NEG_INF), dpMin(k + 1, POS_INF);
        dpMax[0] = 1;
        dpMin[0] = 1;

        for (int idx = 0; idx < n; idx++) {
            long long x = arr[idx];
            int upper = min(k, idx + 1);
            for (int j = upper; j >= 1; j--) {
                long long candMax = dpMax[j];
                long long candMin = dpMin[j];

                if (dpMax[j - 1] != NEG_INF) {
                    long long p = dpMax[j - 1] * x;
                    candMax = max(candMax, p);
                    candMin = min(candMin, p);
                }
                if (dpMin[j - 1] != POS_INF) {
                    long long p = dpMin[j - 1] * x;
                    candMax = max(candMax, p);
                    candMin = min(candMin, p);
                }

                dpMax[j] = candMax;
                dpMin[j] = candMin;
            }
        }

        return (int) dpMax[k];
    }
};