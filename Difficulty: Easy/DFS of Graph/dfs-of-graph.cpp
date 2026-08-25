class Solution {
    void f(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& result){
        vis[node] = true;
        result.push_back(node);
        for(auto &n : adj[node]){
            if(!vis[n]) f(n,adj,vis,result);
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> vis(n, false);
        vector<int> result;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                f(i,adj,vis,result);
            }
        }
        return result;
    }
};