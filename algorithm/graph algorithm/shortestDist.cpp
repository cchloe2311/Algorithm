#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
using namespace std;

int getShortestDist(int s, int e, vector<int> *graph, int n) {
    queue<pair<int, int>> q;
    int *visited = new int[n];
    memset(visited, 0, sizeof(int) * n);

    q.push({s, 0});
    visited[s] = 1;

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        for (int i = 0; i < graph[front.first].size(); i++) {
            int next = graph[front.first][i];

            if (next == e) {
                return (front.second + 1);
            }

            if (visited[next] == 0) {
                q.push({next, (front.second + 1)});
                visited[next] = 1;
            }
        }
    }

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> *graph = new vector<int>[n];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int s, e;
    cin >> s >> e;

    cout << getShortestDist(s, e, graph, n);
}