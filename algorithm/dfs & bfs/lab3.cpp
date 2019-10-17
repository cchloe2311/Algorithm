#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <limits.h>

#define MAX_SIZE 50
#define VIRUS 2
using namespace std;

int n, m;
int map[MAX_SIZE][MAX_SIZE];
int orgMap[MAX_SIZE][MAX_SIZE];
vector<pair<int, int>> virusPos;

int dy[4] = {0, 0, +1, -1};
int dx[4] = {+1, -1, 0, 0};

queue<pair<int, int>> q;

void initVar() {
    cin >> n >> m;

    while(!q.empty()) q.pop();
    while(!virusPos.empty()) virusPos.pop_back();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> orgMap[i][j];

            if (orgMap[i][j] == VIRUS) {
                virusPos.push_back({i, j});
            }
        }
    }
}

bool isInRange(int y, int x) {
    return (y >= 0) && (y < n) && (x >= 0) && (x < n);
}

void spreadVirus(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int tempY = y + dy[i];
        int tempX = x + dx[i];

        if (isInRange(tempY, tempX) && map[tempY][tempX] == 0) {
            map[tempY][tempX] = VIRUS;
            q.push({tempY, tempX});
        }
    }
}

bool isDone() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (map[i][j] == 0) return false;
    }

    return true;
}

int run() {
    int time = 0;
    while(!isDone()) {
        time++;

        int numOfPos = q.size();
        for (int i = 0; i < numOfPos; i++) {
            spreadVirus(q.front().first, q.front().second);
            q.pop();
        }

        if (q.empty()) return INT_MAX;
    }

    return time;
}

void copyMap() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) map[i][j] = orgMap[i][j];
    }
}

int main() {
    int turn;
    cin >> turn;

    vector<int> res;

    for (int i = 0; i < turn; i++) {
        initVar();

        vector<int> index;
        for (int i = 0; i < m; i++) index.push_back(1);
        for (int i = 0; i < virusPos.size() - m; i++) index.push_back(0);

        sort(index.begin(), index.end());

        int minSpreadTime = INT_MAX;
        do {
            while (!q.empty()) q.pop();
            copyMap();

            for (int i = 0; i < index.size(); i++) {
                if (index[i] == 1) q.push(virusPos[i]);
            }

            int spreadTime = run();
            if (minSpreadTime > spreadTime) minSpreadTime = spreadTime;
        } while (next_permutation(index.begin(), index.end()));

        if (minSpreadTime == INT_MAX) minSpreadTime = -1;

        res.push_back(minSpreadTime);
    }

    for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
}