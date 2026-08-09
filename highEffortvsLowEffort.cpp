#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int f(vector<int>& h, vector<int>& l, int idx, int prev, 
    vector<vector<int>>& dp){
        int n=h.size();
        if(idx>=n) return 0;
        if(dp[idx][prev]!=-1) return dp[idx][prev];
        // no perform
        int no_perform=0;
        no_perform+=f(h,l,idx+1,1, dp);
        //lowest perform
        int lowest_perform=0;
        lowest_perform+=(l[idx]+f(h,l,idx+1,0,dp));
        // highest perform
        int highest_perform=0;
        if(prev) highest_perform+=(h[idx]+f(h,l,idx+1,0,dp));
        
        return dp[idx][prev]= max({no_perform, lowest_perform, highest_perform});
    }
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        vector<vector<int>>dp(h.size(), vector<int>(2,-1));
        return f(h,l,0,1,dp);
    }
};