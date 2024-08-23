#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    void dijkstra(
        unordered_map<int, vector<pair<int, int>>>& graph,
        vector<int>& distances, 
        int start, int dst,
        int k
    ) 
    {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        minHeap.push({0, 0, start});

        distances[start] = 0;

        while (!minHeap.empty()) {
            auto [curK, curW, curV] = minHeap.top();
            minHeap.pop();

            if (curK > k) continue;
            
            for (auto [nV, nW] : graph[curV]) {
                int d = curW + nW;
                
                if (d > distances[nV]) 
                    continue;
                
                distances[nV] = d;
                minHeap.push({curK + 1, curW + nW, nV});
            }
        }
    }

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto f : flights) graph[f[0]].push_back({f[1], f[2]});

        vector<int> distances(n, INT_MAX);
        dijkstra(graph, distances, src, dst, k);

        int result = distances[dst];
        return (result == INT_MAX) ? -1 : result;
    }
};
