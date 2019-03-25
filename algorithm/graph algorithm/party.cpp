#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <limits.h>

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

void getShortestDist(int *shortestDist, vector<Node> *graph, int n) {
    bool *isMin = new bool[n + 1];
    memset(isMin, false, sizeof(bool) * (n + 1));

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
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Node> *graph = new vector<Node>[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back(Node(b, c));
    }

    int *shortestDist = new int[n + 1];
    int path = 0;

    fill(shortestDist, shortestDist + (n + 1), INT_MAX);
    shortestDist[k] = 0;

    getShortestDist(shortestDist, graph, n);

    for (int i = 1; i <=n; i++) {
        path += shortestDist[i];
    }

    for (int i = 1; i <=n; i++) {
        if (i != k) {
            fill(shortestDist, shortestDist + (n + 1), INT_MAX);
            shortestDist[i] = 0;

            getShortestDist(shortestDist, graph, n);

            path += shortestDist[k];
        }
    }

    cout << path;
}