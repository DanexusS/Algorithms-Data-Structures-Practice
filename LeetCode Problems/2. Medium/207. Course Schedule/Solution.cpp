#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    bool has_cycle(unordered_map<int, vector<int>>& graph, vector<bool>& v, vector<bool>& s, int u) {
        if (!v[u]) {
            v[u] = true;
            s[u] = true;

            for (auto n : graph[u])
                if (!v[n] && has_cycle(graph, v, s, n) || s[n])
                    return true;
        }

        s[u] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjL;

        for (auto p : prerequisites) {
            adjL[p[0]].push_back(p[1]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> stack(numCourses, false);

        for (auto p : adjL) {
            if (visited[p.first]) continue;

            if (has_cycle(adjL, visited, stack, p.first)) 
                return false;
        }

        return true;
    }
};
