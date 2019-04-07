#include <iostream>
#include <string.h>
#include <vector>
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

int getMin(int flag, vector<vector<int>> preCases) {
    int size = v.size();
    vector<vector<int>> curCases;

    for (int i = 0; i < preCases.size(); i++) {
        for (int j = 0; j < preCases[i].size(); j++) {
            map[v[preCases[i][j]].y][v[preCases[i][j]].x] = true;
        }

        for (int j = 0; j < size; j++) {
            int y = v[j].y;
            int x = v[j].x;

            if (isPossibleIdx(y, x)) {
                map[y][x] = true;

                if (getOutput()) {
                    return flag;
                }
                else {
                    map[y][x] = false; // 되돌리기

                    vector<int> newCase(preCases[i]);
                    newCase.push_back(j);

                    curCases.push_back(newCase);
                }
            }
        }

        for (int j = 0; j < preCases[i].size(); j++) {
            map[v[preCases[i][j]].y][v[preCases[i][j]].x] = false;
        }
    }

    if (flag == 3) return -1;
    else return getMin(++flag, curCases);
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
        vector<vector<int>> initCases;
        initCases.push_back({});

        cout << getMin(1, initCases);
    }
}