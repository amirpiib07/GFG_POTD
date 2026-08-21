class Solution {
  public:
    int transform(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        
        if(n!=m) return -1;
        
        vector<int> mpp(256,0);
        
        for(auto &ch : s1){
            mpp[ch]++;
        }
        for(auto &ch : s2) mpp[ch]--;
        
        for(auto &it : mpp) if(it!=0) return -1;
        
        int i = n-1, j = n-1;
        int count = 0;
        while(i>=0){
            if(s1[i]==s2[j]) {
                i--;j--;
            }else{
                i--;
                count++;
            }
        }
        
        return count;
        
    }
};
