#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        int result = 0;
        unordered_set<int> visited;

        visited.insert(0);
        for (int i = 1; i < n; ++i)
            pq.push({abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]), 0, i});

        while (visited.size() < n) {
            auto [w, from, to] = pq.top();
            pq.pop();

            if (visited.count(to) > 0) continue;

            result += w;
            visited.insert(to);

            for (int i = 0; i < n; ++i) {
                if (to == i || visited.count(i) > 0) continue;

                pq.push({abs(points[to][0] - points[i][0]) + abs(points[to][1] - points[i][1]), to, i});
            }
        }

        return result;
    }
};
