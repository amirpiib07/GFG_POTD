class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mpp;
        int maxi = 0;
        for(auto &num : arr){
            if(mpp.count(num-1)){
                mpp[num]+=(1+mpp[num-1]);
                maxi = max(maxi, mpp[num]);
            }
            else{
                mpp[num]++;
                maxi = max(maxi, mpp[num]);
            }
        }
        
        return n - maxi;
    }
};