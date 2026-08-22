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
}; */

class Solution {
    Node* findLCA(Node* root, int p, int q) {
        if (!root) return nullptr;
        if (root->data == p || root->data == q) return root;

        Node* left = findLCA(root->left, p, q);
        Node* right = findLCA(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }

    bool dfs(Node* curr, int target, bool isLeft, int turns, int& ans) {
        if (!curr) return false;

        if (curr->data == target) {
            ans = turns;
            return true;
        }

        if (isLeft) {
            if (dfs(curr->left, target, true, turns, ans)) return true;
            if (dfs(curr->right, target, false, turns + 1, ans)) return true;
        } else {
            if (dfs(curr->left, target, true, turns + 1, ans)) return true;
            if (dfs(curr->right, target, false, turns, ans)) return true;
        }

        return false;
    }

    int getTurnsFromLCA(Node* lca, int target) {
        int turns = 0;

        if (dfs(lca->left, target, true, 0, turns)) return turns;
        if (dfs(lca->right, target, false, 0, turns)) return turns;

        return 0;
    }

public:
    int numberOfTurns(Node* root, int p, int q) {
        Node* LCA = findLCA(root, p, q);
        if (!LCA) return -1;

        // Case 1: Agar LCA khud p ya q ho
        if (LCA->data == p || LCA->data == q) {
            int target = (LCA->data == p) ? q : p;
            int turns = getTurnsFromLCA(LCA, target);
            return (turns == 0) ? -1 : turns;
        }

        // Case 2: Agar p aur q alag subtrees mein hon
        int turnsP = getTurnsFromLCA(LCA, p);
        int turnsQ = getTurnsFromLCA(LCA, q);
        return turnsP + turnsQ + 1;
    }
};