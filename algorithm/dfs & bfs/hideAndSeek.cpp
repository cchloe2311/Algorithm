#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int getTurn(int n, int k) {
    vector<int> visited;
    queue<pair<int, int>> q;

    q.push({n, 0});
    visited.push_back(n);

    if (n == k) return q.front().first;

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        int temp = front.first + 1;
        if (temp == k) return front.second + 1;
        else if(find(visited.begin(), visited.end(), temp) == visited.end()) {
            q.push({temp, front.second + 1});
            visited.push_back(temp);
        }

        temp = front.first - 1;
        if (temp == k) return front.second + 1;
        else if(find(visited.begin(), visited.end(), temp) == visited.end()) {
            q.push({temp, front.second + 1});
            visited.push_back(temp);
        }

        temp = front.first * 2;
        if (temp == k) return front.second + 1;
        else if(find(visited.begin(), visited.end(), temp) == visited.end()) {
            q.push({temp, front.second + 1});
            visited.push_back(temp);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << getTurn(n, k);
}