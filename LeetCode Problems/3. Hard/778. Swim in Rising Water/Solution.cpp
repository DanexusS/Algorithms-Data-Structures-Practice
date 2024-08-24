#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distances(n, vector(n, -1));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> queue;

        queue.push({grid[0][0], {0, 0}});
        distances[0][0] = grid[0][0];

        while (!queue.empty()) {
            auto [curT, current] = queue.top();
            auto [curX, curY] = current;

            queue.pop();

            for (auto [dx, dy] : directions) {
                int x = curX + dx, y = curY + dy;

                if (x < 0 || y < 0 || x >= n || y >= n) continue;
                if (distances[x][y] != -1) continue;

                distances[x][y] = max(distances[curX][curY], grid[x][y]);
                queue.push({grid[x][y], {x, y}});
            }
        }

        return distances[n - 1][n - 1];
    }
};
