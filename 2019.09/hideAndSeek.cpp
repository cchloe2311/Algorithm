#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 200001
#define NOT_VISITED -1

int visited[MAX];
queue<int> q;

int n, k;

void initVar() {
    memset(visited, NOT_VISITED, sizeof(int)*MAX);
    while (!q.empty()) q.pop();

    q.push(n);
    visited[n] = 0;
}

int getDepth() {
    initVar();

    while(!q.empty()) {
        int lastPosition = q.front();
        q.pop();

        if (lastPosition == k) return visited[lastPosition];

        if (visited[lastPosition - 1] == NOT_VISITED) {
            q.push(lastPosition - 1);
            visited[lastPosition - 1] = visited[lastPosition] + 1;
        }
        if (visited[lastPosition + 1] == NOT_VISITED) {
            q.push(lastPosition + 1);
            visited[lastPosition + 1] = visited[lastPosition] + 1;
        }
        if (((lastPosition * 2) < MAX) && (visited[lastPosition * 2] == NOT_VISITED)) {
            q.push(lastPosition * 2);
            visited[lastPosition * 2] = visited[lastPosition] + 1;
        }
    }

    return -1;
}

int main() {
    cin >> n >> k;

    cout << getDepth();
}