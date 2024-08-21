#include "bits/stdc++.h"

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    void dfs(Node* current, map<int, Node*>& mapped_graph, map<int, bool>& visited) {
        visited[current->val] = true;

        cout << current->val << " ";

        for (auto n : current->neighbors) {
            if (visited[n->val]) {
                mapped_graph[current->val]->neighbors.push_back(mapped_graph[n->val]);
                continue;
            }

            mapped_graph[n->val] = new Node(n->val);
            mapped_graph[current->val]->neighbors.push_back(mapped_graph[n->val]);

            dfs(n, mapped_graph, visited);
        }
    }

public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        map<int, Node*> mapped_graph;
        map<int, bool> visited;

        mapped_graph[node->val] = new Node(node->val);
        dfs(node, mapped_graph, visited);

        return mapped_graph[node->val];
    }
};
