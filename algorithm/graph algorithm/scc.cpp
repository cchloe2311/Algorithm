#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <string.h>
#include <algorithm>

using namespace std;

vector<int> getDfsNum(vector<int> *graph, int n) {
    vector<int> numV;

    stack<int> s;
    int *visited = new int[n + 1];
    memset(visited, 0, sizeof(int) * (n + 1));

    for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                s.push(i);
                visited[i] = 1;
            }

            while (!s.empty()) {
                int top = s.top();
                bool isDone = true;

                for (int j = 0; j < graph[top].size(); j++) {
                    if (visited[graph[top][j]] == 0) {
                        s.push(graph[top][j]);
                        visited[graph[top][j]] = 1;
                        isDone = false;

                        break;
                    }
                }

                if (isDone) {
                    s.pop();
                    numV.push_back(top);
                }
            }
    }



    return numV;
}

void findGroup(vector<int> &grouped, vector<int> *reversedGraph, int n, int start) {
    stack<int> s;
    int *visited = new int[n + 1];
    memset(visited, 0, sizeof(int) * (n + 1));

    s.push(start);
    visited[start] = 1;

    while (!s.empty()) {
        int top = s.top();
        s.pop();
        grouped.push_back(top);

        for (int i = 0; i < reversedGraph[top].size(); i++) {
            if ((visited[reversedGraph[top][i]] == 0)
                && (find(grouped.begin(), grouped.end(), reversedGraph[top][i]) == grouped.end())) {
                s.push(reversedGraph[top][i]);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> *graph = new vector<int>[n + 1];
    vector<int> *reversedGraph = new vector<int>[n + 1];

    for (int i = 0; i < m; i++) {
        int src, dest;
        cin >> src >> dest;

        graph[src].push_back(dest);
        reversedGraph[dest].push_back(src);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
        sort(reversedGraph[i].begin(), reversedGraph[i].end());
    }

    vector<int> numV = getDfsNum(graph, n);

    vector<int> grouped;
    int group = 0;
    for (int i = (numV.size() - 1); i >=0; i--) {
        auto it = find(grouped.begin(), grouped.end(), numV[i]);

        if (it == grouped.end()) {
            findGroup(grouped, reversedGraph, n, numV[i]);
            group++;
        }
    }

    cout << group;
}