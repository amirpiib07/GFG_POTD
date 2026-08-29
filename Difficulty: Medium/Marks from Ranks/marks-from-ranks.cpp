class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        vector<int> arr;
        int n = l.size();
        for(int i = 0; i < n; i++){
            int u = l[i];
            int v = r[i];
            for(int mark = u; mark <= v; mark++){
                arr.push_back(mark);
            }
        }
        int m = rank.size();
        for(int i = 0; i < m; i++){
            rank[i] = arr[rank[i] - 1];
        } 
        
        return rank;
    }
};