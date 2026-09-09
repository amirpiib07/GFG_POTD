class Solution {
  public:
    int pairCount(int x, int y) {
        int ans = 0;
        int n = x * y;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                int a = i;
                int b = n / i;
                if(gcd(a, b) == x && lcm(a,b) == y){
                    if(a == b) ans++;
                    else ans+=2;
                }
            }
        }
        return ans;
    }
};