#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, m, h;
bool map[31][11] = {false,};

class Pos {
public:
    int y;
    int x;

    Pos(int y, int x) {
        this->y = y;
        this->x = x;
    }
};

vector<Pos> v;

bool isInRange(int y, int x) {
    if ((y > 0) && (y <= h) && (x > 0) && (x <= n)) return true;
    else return false;
}

bool getOutput() {
    for (int i = 1; i <= n; i++) {
        int l = i - 1;
        int r = i;

        for (int j = 1; j <= h; j++) {
            if (isInRange(j, l) && map[j][l]) {
                l--;
                r--;
            }
            else if (isInRange(j, r) && map[j][r]) {
                l++;
                r++;
            }
        }

        if (r != i) return false;
    }

    return true;
}

bool isPossibleIdx(int y, int x) {

    // ㅇㅏ예 범위를 벗어난 경우
    if (!isInRange(y, x)) return false;

    // 그 자리에 이미 사다리가 있는 경우
    else if (map[y][x]) return false;

    // 좌우에 다른 사다리가 있는 경우 // 연속해 놓을 수 없음
    else if (isInRange(y, x - 1) && (map[y][x - 1])) return false;
    else if (isInRange(y, x + 1) && (map[y][x + 1])) return false;

    return true;
}

int getMin(queue<vector<int>> preCases) {
    int size = v.size();

    while (!preCases.empty()) {
        vector<int> front = preCases.front();
        preCases.pop();

        for (int j = 0; j < front.size(); j++) {
            map[v[front[j]].y][v[front[j]].x] = true;
        }

        for (int j = 0; j < size; j++) {
            int y = v[j].y;
            int x = v[j].x;

            if (isPossibleIdx(y, x)) {
                map[y][x] = true;

                if (getOutput()) {
                    return (front.size() + 1);
                }
                else {
                    map[y][x] = false; // 되돌리기

                    vector<int> newCase(front);
                    newCase.push_back(j);

                    if (newCase.size() > 3) {
                        return -1;
                    }
                    else preCases.push(newCase);
                }
            }
        }

        for (int j = 0; j < front.size(); j++) {
            map[v[front[j]].y][v[front[j]].x] = false;
        }
    }

    return -1;
}

int main() {
    cin >> n >> m >> h;

    for (int i = 0; i < m; i++) {
        int y, x;
        cin >> y >> x;

        map[y][x] = true;
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j < n; j++) {
            if (!map[i][j]) v.push_back(Pos(i, j));
        }
    }

    if (getOutput()) {
        cout << 0;
    }
    else {
        queue<vector<int>> initCases;
        initCases.push({});

        cout << getMin(initCases);
    }
}