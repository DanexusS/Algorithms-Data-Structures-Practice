#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    bool bfs(vector<vector<int>> graph, int start, int end, vector<bool>& v) {
        queue<int> q;

        q.push(start);
        v[start] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (cur == end) return true;

            for (auto n : graph[cur]) {
                if (v[n]) continue;
                if (n == end) return true;

                q.push(n);
                v[n] = true;
            }
        }

        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjL(n);

        for (auto p : edges) {
            adjL[p[0]].push_back(p[1]);
            adjL[p[1]].push_back(p[0]);
        }

        vector<bool> visited(n);
        return bfs(adjL, source, destination, visited);
    }
};
