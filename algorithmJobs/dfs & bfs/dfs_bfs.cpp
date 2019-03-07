#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int getDest(vector<int> neighbor, int *visited) {
    for (int i = 0; i < neighbor.size(); i++) {
        if(visited[neighbor[i]] == 0) return neighbor[i];
    }

    return -1;
}

void getDfs(vector<int> *graph, int n) {
    stack<int> s;
    int *visited = new int[n];
    memset(visited, 0, sizeof(int)*n);

    s.push(0);
    visited[0] = 1;

    cout << 0 << " ";

    while (!s.empty()) {
        int next = getDest(graph[s.top()], visited);

        if (next == -1) {
            s.pop();
        }

        else {
            s.push(next);
            visited[next] = 1;

            cout << next << " ";
        }
    }

    cout << endl;
}

void getBfs(vector<int> *graph, int n){
    queue<int> q;
    int *visited = new int[n];
    memset(visited, 0, sizeof(int)*n);

    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        cout << front << " ";

        for (int i = 0; i < graph[front].size(); i++) {
            if(visited[graph[front][i]]  == 0) {
                q.push(graph[front][i]);
                visited[graph[front][i]] = 1;
            }
        }
    }

    cout << endl;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> *graph = new vector<int>[n];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < n; i++) sort(graph[i].begin(), graph[i].end());

    getDfs(graph, n);
    getBfs(graph, n);
}