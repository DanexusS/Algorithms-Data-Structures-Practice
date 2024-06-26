#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void setAvailableSlots(
        const int& n,
        vector<vector<bool>>& available,
        const int& c, 
        const int& level
        ) 
    {
        for (int a = 0; a < n; ++a) {
            int d1 = c - a + level, d2 = c + a - level;

            if (d1 >= 0 && d1 < n) available[a][d1] = false;
            if (d2 >= 0 && d2 < n) available[a][d2] = false;
            available[level][a] = false;
            available[a][c] = false;
        }
    }

    void traverse(
        const int& n,
        vector<vector<string>>& result,
        vector<vector<bool>>& available,
        vector<string> field,
        int level,
        int x, int y
        )
    {
        if (level == n) {
            result.push_back(field);
            return;
        }

        for (int c = 0; c < n; ++c) {
            if (!available[level][c])
                continue;
                
            field[level][c] = 'Q';
            vector<vector<bool>> avail = available;
            setAvailableSlots(n, avail, c, level);
            
            traverse(n, result, avail, field, level + 1, level, c);

            field[level][c] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<vector<bool>> available(n, vector(n, true));

        traverse(n, result, available, vector(n, string(n, '.')), 0, 0, 0);

        return result;
    }
};