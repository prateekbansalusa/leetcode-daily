#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, numeric_limits<int>::max()));
        queue<pair<int, int>> q;

        // Initialize queue with all 0s and set their distance to 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions for moving up, down, left, right
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // BFS starting from all 0s simultaneously
        while (!q.empty()) {
            auto [currR, currC] = q.front();
            q.pop();

            for (auto& dir : dirs) {
                int newR = currR + dir[0];
                int newC = currC + dir[1];

                // Check bounds and if we found a shorter path
                if (newR >= 0 && newR < m && newC >= 0 && newC < n) {
                    if (dist[newR][newC] > dist[currR][currC] + 1) {
                        dist[newR][newC] = dist[currR][currC] + 1;
                        q.push({newR, newC});
                    }
                }
            }
        }

        return dist;
    }
};
