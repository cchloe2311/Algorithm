#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int cntConnectedComp(vector<int> *graph, int v) {
    int *grouped = new int[v + 1];
    memset(grouped, 0, sizeof(int) * (v + 1));
    queue<int> q;

    int numOfCC = 0;

    for (int i = 1; i <= v; i++) {
        if (grouped[i] == 0) {
            q.push(i);
            grouped[i] = 1;

            numOfCC++;
        }

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            for (int j = 0; j < graph[front].size(); j++) {
                if (grouped[graph[front][j]] == 0) {
                    q.push(graph[front][j]);
                    grouped[graph[front][j]] = 1;
                }
            }
        }
    }

    return numOfCC;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<int> *graph = new vector<int>[v + 1]; // 0~v

    for (int i = 0; i< e; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << cntConnectedComp(graph, v);
}