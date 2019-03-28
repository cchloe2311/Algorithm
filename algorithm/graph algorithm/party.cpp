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
    vector<Node> *reversed = new vector<Node>[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back(Node(b, c));
        reversed[b].push_back(Node(a, c));
    }

    int *shortestDist = new int[n + 1];
    int path = 0;

    fill(shortestDist, shortestDist + (n + 1), INT_MAX);
    shortestDist[k] = 0;

    getShortestDist(shortestDist, graph, n);

    for (int i = 1; i <=n; i++) {
        path += shortestDist[i];
    }

    // 다른 마을에서 철수네 마을까지의 최단거리는 reversed 그래프를 이용해 한번에 구할 수 있다.
    // 그냥 그래프 : 다른마을 -> 철수네 == 리버스 그래프 : 철수네 ->다른마을
    fill(shortestDist, shortestDist + (n + 1), INT_MAX);
    shortestDist[k] = 0;

    getShortestDist(shortestDist, reversed, n);

    for (int i = 1; i <=n; i++) {
        path += shortestDist[i];
    }

    cout << path;
}