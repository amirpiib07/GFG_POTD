/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
    void dfs(Node* root, int l, vector<int>& arr, int& k){
        if(!root) return;
        if(l > k) return;
        if(!root->left && !root->right){
            arr[l]++;
        }
        dfs(root->left, l + 1, arr, k);
        dfs(root->right, l + 1, arr, k);
        return;
    }
    
  public:
    int getCount(Node *root, int k) {
        // code here
        vector<int> arr(k + 1, 0);
        dfs(root, 1, arr, k);
        int ans = 0;
        int n = k;
        for(int i = 1; i <= k; i++){
            while(arr[i] > 0 && n >= i){
                ans++;
                arr[i]--;
                n -= i;;
            }
        }
        return ans;
    }
};