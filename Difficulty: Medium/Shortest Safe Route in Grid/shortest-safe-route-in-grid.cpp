class Solution {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

public:
    int shortestPath(vector<vector<int>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        // Store original mines
        vector<pair<int, int>> mines;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    mines.push_back({i, j});
                }
            }
        }

        // Mark mine + adjacent cells unsafe
        for (auto [r, c] : mines) {

            mat[r][c] = 0;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m) {

                    mat[nr][nc] = 0;
                }
            }
        }

        queue<pair<int, int>> q;

        // dist[i][j] = number of cells in path
        vector<vector<int>> dist(n, vector<int>(m, -1));

        // ANY safe cell in first column
        for (int i = 0; i < n; i++) {

            if (mat[i][0] == 1) {

                q.push({i, 0});
                dist[i][0] = 1;
            }
        }

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            // Reached ANY safe cell in last column
            if (c == m - 1) {
                return dist[r][c];
            }

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    mat[nr][nc] == 1 &&
                    dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }
};