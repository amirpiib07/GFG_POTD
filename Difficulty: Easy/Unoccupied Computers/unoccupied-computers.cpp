class Solution {
  public:
    int solve(int n, string s) {
        // code here
        vector<int> m(26, 0);
        //int m = s.size();
        int ans = 0;
        for(char &ch : s){
            if(m[ch - 'A'] == 0 && n > 0){
                n--;
                m[ch - 'A']++;
            }
            else if(m[ch - 'A'] == 1){
                n++;
                
            }
            
            else if(m[ch - 'A'] == 0 && n == 0) {
                ans++;
                m[ch - 'A'] = -1;
            }
            else if( m[ch - 'A'] == -1) ans++;
        }
        return ans / 2;
    }
};
