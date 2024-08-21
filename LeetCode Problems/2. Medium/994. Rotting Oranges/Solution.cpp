#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    void bfs(
        vector<vector<int>>& grid,
        vector<vector<bool>>& visited, 
        vector<vector<int>>& distances, 
        int& result, 
        vector<pair<int, int>>& directions, 
        pair<int, int> start, 
        int m, int n
        ) 
    {
        queue<pair<int, int>> q;

        visited[start.first][start.second] = true;
        q.push(start);

        while (!q.empty()) {
            auto [cur_x, cur_y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int x = cur_x + dx, y = cur_y + dy;

                if (x >= m || y >= n || x < 0 || y < 0 || visited[x][y] || grid[x][y] == 0) 
                    continue;

                q.push({x, y});
                visited[x][y] = true;
                distances[x][y] = min(distances[x][y], distances[cur_x][cur_y] + 1);
            }
        }
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> distances(m, vector(n, 1000000));
        vector<pair<int, int>> rottens;

        int oranges = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                if (grid[i][j] == 1) {
                    ++oranges;
                    continue;
                }

                rottens.push_back({i, j});
                distances[i][j] = 0;
            }
        }

        if (oranges == 1) return 0;
        if (rottens.size() == 0) return -1;
        
        int result = 0;

        for (auto rot_coord : rottens) {
            vector<vector<bool>> visited(m, vector(n, false));
            bfs(grid, visited, distances, result, directions, rot_coord, m, n);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && distances[i][j] == 1000000) return -1;
                if (grid[i][j] == 0) continue;

                result = max(result, distances[i][j]);
            }
        }

        return result;
    }
};
