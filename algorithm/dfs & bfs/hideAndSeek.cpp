#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

#define MAX 200001

int getTurn(int n, int k) {
    int visited[MAX] = {0};
    queue<pair<int, int>> q;

    q.push({n, 0});
    visited[n] = 1;

    if (n == k) return q.front().second;

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        int temp = front.first + 1;
        if (temp == k) return front.second + 1;
        else if(visited[temp] == 0) {
            q.push({temp, front.second + 1});
            visited[temp] = 1;
        }

        temp = front.first - 1;
        if (temp == k) return front.second + 1;
        else if((temp >= 0) && (visited[temp] == 0)) {
            q.push({temp, front.second + 1});
            visited[temp] = 1;
        }

        temp = front.first * 2;
        if (temp == k) return front.second + 1;
        else if((temp < MAX) && (visited[temp] == 0)) {
            q.push({temp, front.second + 1});
            visited[temp] = 1;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << getTurn(n, k);
}