#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int cur, int& nvis) {
        ++nvis;
        visited[cur] = true;

        for (int n : graph[cur]) {
            if (visited[n]) continue;
            dfs(graph, visited, n, nvis);
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int nvisited = 0;
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(rooms, visited, 0, nvisited);

        return nvisited == n;
    }
};
