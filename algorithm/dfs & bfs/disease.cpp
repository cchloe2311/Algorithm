#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

void bfs(queue<int> q, int *visited, int n) {
    if (q.empty()) {
        return;
    }

    int front = q.front();
    q.pop();
    int value = front * 2;

    if ((value <= n) && (visited[value] == 0)) {
        q.push(value);
        visited[value] = 1;
    }

    value = front / 3;

    if ((value != 0) && (visited[value] == 0)) {
        q.push(value);
        visited[value] = 1;
    }

    bfs(q, visited, n);
}

int main() {
    int n, k;
    cin >> n >> k;

    // 가짓수는 2가지 밖에 없음 > bfs
    queue<int> q;
    int *visited = new int[n + 1];
    memset(visited, 0, (sizeof(int) * (n + 1)));

    q.push(k);
    visited[k] = 1;

    bfs(q, visited, n);

    int count = 0;

    // 범위조심
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) count++;
    }

    cout << count;
}