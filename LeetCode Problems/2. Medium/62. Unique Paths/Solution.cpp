#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid_ways(m, vector(n, 0));

        grid_ways[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) 
                    grid_ways[i][j] = 1;
                else
                    grid_ways[i][j] = grid_ways[i - 1][j] + grid_ways[i][j - 1];
            }
        }

        return grid_ways[m - 1][n - 1];
    }
};
