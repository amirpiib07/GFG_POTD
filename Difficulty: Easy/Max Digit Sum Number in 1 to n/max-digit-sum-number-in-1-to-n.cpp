class Solution {
public:
    int findMax(int n) {
        int ans = n;

        string s = to_string(n);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                continue;

            string candidate = s;

            candidate[i]--;

            for (int j = i + 1; j < s.size(); j++) {
                candidate[j] = '9';
            }

            int num = stoi(candidate);

            int sum1 = 0, sum2 = 0;
            int x = ans, y = num;

            while (x > 0) {
                sum1 += x % 10;
                x /= 10;
            }

            while (y > 0) {
                sum2 += y % 10;
                y /= 10;
            }

            if (sum2 > sum1 || (sum2 == sum1 && num > ans)) {
                ans = num;
            }
        }

        return ans;
    }
};