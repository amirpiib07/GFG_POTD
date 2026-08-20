/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    int ans = INT_MIN;

    int dfs(Node* root) {
        if (!root)
            return INT_MAX;

        int leftMin = dfs(root->left);
        int rightMin = dfs(root->right);

        int minValue = min(root->data, min(leftMin, rightMin));

        // root and any descendant
        if (leftMin != INT_MAX)
            ans = max(ans, root->data - leftMin);

        if (rightMin != INT_MAX)
            ans = max(ans, root->data - rightMin);

        return minValue;
    }

public:
    int maxDiff(Node* root) {
        if (!root)
            return INT_MIN;

        dfs(root);

        return ans;
    }
};
