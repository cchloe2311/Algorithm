#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <string.h>

using namespace std;

vector<pair<int, int>> getDfsNum(vector<int> *graph, int n) {
    stack<int> s;
    int *visited = new int[n + 1];
    memset(visited, 0, sizeof(int) * (n + 1));

    s.push(1);
    visited[1] = 1;

    int time = 1;
    vector<pair<int, int>> numV; // first : 순서, second : index
    while (!s.empty()) {
        int top = s.top();
        bool isDone = true;

        for (int i = 0; i < graph[top].size(); i++) {
            if (visited[graph[top][i]] == 0) {
                s.push(graph[top][i]);
                visited[graph[top][i]] = 1;
                isDone = false;

                break;
            }
        }

        if (isDone) {
            s.pop();
            numV.push_back({time++, top});
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
        cout << top << " ";

        for (int i = 0; i < reversedGraph[top].size(); i++) {
            if ((visited[reversedGraph[top][i]] == 0)
            && (find(grouped.begin(), grouped.end(), reversedGraph[top][i]) == grouped.end())) {
                s.push(reversedGraph[top][i]);
            }
        }
    }
    cout << endl;
}

int main() {
    /**
     * 구현 steps
     *
     * 1. 그래프 입력받기
     * 2. dfs의 스택에서 빠져나오는 순서를 기록
     * 3. 뒤집은 그래프에 대해 빠져나온 순서가 늦은 노드부터 순회 // 순회 by DFS
     *      getItsGroup(node) // 해당 노드가 속하는 모든 정점들을 get! => aka Group
     * 4. 이를 통해 같은 그룹을 지음
     * 5. 특정 그룹에 속한 노드는 이제 제
     */

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

    vector<pair<int, int>> numV = getDfsNum(graph, n);

    vector<int> grouped;
    int group = 0;
    for (int i = (numV.size() - 1); i >=0; i--) {
        auto it = find(grouped.begin(), grouped.end(), numV[i].second);

        if (it == grouped.end()) {
            findGroup(grouped, reversedGraph, n, numV[i].second);
            group++;
        }
    }

    cout << group;
}