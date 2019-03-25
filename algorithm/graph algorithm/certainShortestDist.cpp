#include <iostream>
#include <limits.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

class Node {
public:
    int id;
    int weight;

    Node(int id, int weight) {
        this->id = id;
        this->weight = weight;
    }
};

pair<int, int> getShortestDist(int src, int destA, int destB, int n, vector<Node> *graph) {
    bool *isMin = new bool[n + 1];
    memset(isMin, false, sizeof(bool) * (n + 1));

    int *shortestDist = new int[n + 1];
    fill(shortestDist, shortestDist + (n + 1), INT_MAX);
    shortestDist[src] = 0;

    for (int i = 0; i < n; i++) {
        int minValue = INT_MAX;
        int minIdx = -1;

        for (int j = 1; j <= n; j++) {
            if (!isMin[j] && (shortestDist[j] < minValue)) {
                minValue = shortestDist[j];
                minIdx = j;
            }
        }

        isMin[minIdx] = true;

        for (int j = 0; j < graph[minIdx].size(); j++) {
            int tempValue = shortestDist[minIdx] + graph[minIdx][j].weight;
            if (tempValue < shortestDist[graph[minIdx][j].id]) {
                shortestDist[graph[minIdx][j].id] = tempValue;
            }
        }
    }

    return {shortestDist[destA], shortestDist[destB]};
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Node> *graph = new vector<Node>[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back(Node(b, c));
        graph[b].push_back(Node(a, c));
    }

    int nodeA, nodeB;
    cin >> nodeA >> nodeB;

    int pathA = 0, pathB = 0;

    pair<int, int> shortestDist = getShortestDist(1, nodeA, nodeB, n, graph);
    pathA += shortestDist.first;
    pathB += shortestDist.second;

    shortestDist = getShortestDist(nodeA, nodeB, nodeB, n, graph);
    pathA += shortestDist.first;
    pathB += shortestDist.second;

    shortestDist = getShortestDist(n, nodeB, nodeA, n, graph);
    pathA += shortestDist.first;
    pathB += shortestDist.second;

    cout << min(pathA, pathB);
}