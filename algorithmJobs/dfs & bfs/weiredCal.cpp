#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool isVisited(vector<int> visited, int value) {
    if(find(visited.begin(), visited.end(), value) != visited.end()) return true;
    else return false;
}

int main() {
    int n;
    cin >> n;

    // {value, depth}
    queue<pair<int, int> > q;
    vector<int> visited;

    q.push({1, 0});
    visited.push_back(1);

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        int cal = front.first * 2;
        if (cal == n) {
            cout << (front.second + 1);
            return 0;
        }
        else {
            q.push({cal, (front.second + 1)});
        }

        cal = (int)(front.first / 3);
        if (cal == n) {
            cout << (front.second + 1);
            return 0;
        }
        else if (!isVisited(visited, cal)) {
            q.push({cal, (front.second + 1)});
        }
    }

    // TODO 다섯자리가 넘어가는 경우에 대해서도 처리해 줘야함 !!
    // bigger than 9999

}