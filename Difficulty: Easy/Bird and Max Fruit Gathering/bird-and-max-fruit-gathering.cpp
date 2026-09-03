class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int n = arr.size();
        for(int i = 1; i < n; i++){
            arr[i] = arr[i - 1] + arr[i];
        }
        
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            int sum = 0;
            if(i == 0){
                sum = arr[i + m - 1];
                ans = max(ans, sum);
            } else {
                int idx = i + m - 1 > n - 1 ? n - 1 : i + m - 1;
                bool flag = i + m - 1 > n - 1;
                if(flag) {
                    sum += arr[idx] - arr[i - 1];
                    int mod = (i + m - 1) % n;
                    sum += arr[mod];
                    ans = max(ans, sum);
                } else {
                    sum += arr[idx] - arr[i - 1];
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};