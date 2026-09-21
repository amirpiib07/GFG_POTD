class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        // code here

        queue<Node*> q1;
        queue<Node*> q2;

        if (root1->data != root2->data) {
            return false;
        }

        q1.push(root1);
        q2.push(root2);

        unordered_map<int, int> freq;

        while (!q1.empty() && !q2.empty()) {

            int size1 = q1.size();
            int size2 = q2.size();

            if (size1 != size2) return false;

            while (size1--) {

                Node* curr = q1.front();
                q1.pop();

                freq[curr->data]++;

                if (curr->left) {
                    q1.push(curr->left);
                }

                if (curr->right) {
                    q1.push(curr->right);
                }
            }

            while (size2--) {
                Node* curr = q2.front();
                q2.pop();

                freq[curr->data]--;

                if (freq[curr->data] < 0) return false;

                if (curr->left) {
                    q2.push(curr->left);
                }
                if (curr->right) {
                    q2.push(curr->right);
                }
            }
        }

        return q1.empty() && q2.empty();
    }
};