class Solution {
    bool dfs(int nr, int nc, int c, vector<vector<char>>& mat,
             string& word, int idx) {

        
        if (nr < 0 || nc < 0 ||
            nr >= mat.size() || nc >= mat[0].size())
            return false;

        
        if (word[idx] != mat[nr][nc])
            return false;

        
        if (idx == word.size() - 1)
            return true;

        if (c == 0) {
            return dfs(nr - 1, nc - 1, c, mat, word, idx + 1);
        }
        else if (c == 1) {
            return dfs(nr - 1, nc, c, mat, word, idx + 1);
        }
        else if (c == 2) {
            return dfs(nr - 1, nc + 1, c, mat, word, idx + 1);
        }
        else if (c == 3) {
            return dfs(nr, nc - 1, c, mat, word, idx + 1);
        }
        else if (c == 4) {
            return dfs(nr, nc + 1, c, mat, word, idx + 1);
        }
        else if (c == 5) {
            return dfs(nr + 1, nc - 1, c, mat, word, idx + 1);
        }
        else if (c == 6) {
            return dfs(nr + 1, nc, c, mat, word, idx + 1);
        }
        else {
            return dfs(nr + 1, nc + 1, c, mat, word, idx + 1);
        }
    }

public:
    vector<vector<int>> searchWord(vector<vector<char>>& mat, string& word) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] != word[0])
                    continue;

                // Word of length 1
                if (word.size() == 1) {
                    ans.push_back({i, j});
                    continue;
                }

                for (int row = -1; row <= 1; row++) {
                    for (int col = -1; col <= 1; col++) {

                        if (row == 0 && col == 0)
                            continue;

                        int n_row = i + row;
                        int n_col = j + col;

                        int direction;

                        if (row == -1 && col == -1)
                            direction = 0;
                        else if (row == -1 && col == 0)
                            direction = 1;
                        else if (row == -1 && col == 1)
                            direction = 2;
                        else if (row == 0 && col == -1)
                            direction = 3;
                        else if (row == 0 && col == 1)
                            direction = 4;
                        else if (row == 1 && col == -1)
                            direction = 5;
                        else if (row == 1 && col == 0)
                            direction = 6;
                        else
                            direction = 7;

                        if (dfs(n_row, n_col, direction, mat, word, 1)) {
                            ans.push_back({i, j});
                            break;
                        }
                    }

                    
                    if (!ans.empty() &&
                        ans.back()[0] == i &&
                        ans.back()[1] == j)
                        break;
                }
            }
        }

        return ans;
    }
};