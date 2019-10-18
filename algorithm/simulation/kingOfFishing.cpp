#include <iostream>
#include <vector>
#include <algorithm>

#define MAP_MAX 101
using namespace std;

int dy[5] = {0, -1, +1, 0, 0};
int dx[5] = {0, 0, 0, +1, -1};

int redirection[5] = {0, 2, 1, 4, 3};

int r, c, m;
int anglerPos = 1, sumOfSize = 0;

class Shark {
public:
    int s;
    int d;
    int z;

    int time;

    Shark() {
        time = 0;
    }
};

vector<Shark> map[MAP_MAX][MAP_MAX];

void printMap() {
    cout << endl;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (map[i][j].empty()) cout << 0 << "\t";
            else cout << map[i][j].front().s << "\t";
        }
        cout << endl;
    }
}

void initVar() {
    anglerPos = 1, sumOfSize = 0;

    cin >> r >> c >> m;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) map[i][j].clear();
    }

    for (int i = 0; i < m; i++) {
        int r, c;
        Shark newShark;
        cin >> r >> c >> newShark.s >> newShark.d >> newShark.z;

        map[r][c].push_back(newShark);
    }
}

bool isInRange(int y, int x) {
    if ((y > 0) && (y <= r) && (x > 0) && (x <= c)) return true;
    else return false;
}

void huntShark() {
    int huntingR = 1;
    while (huntingR <= r) {
        if (!map[huntingR][anglerPos].empty()) {
            sumOfSize += map[huntingR][anglerPos].front().z;
            map[huntingR][anglerPos].clear();

            break;
        }

        huntingR++;
    }
}

void moveSharks() {
    int time = -1;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (map[i][j].empty()) continue;
            if (time != -1 && map[i][j].front().time != time) continue;

            int tempY = i, tempX = j;
            if (time == -1) time = map[i][j].front().time;

            int leftMove = map[i][j].front().s;
            while(leftMove != 0) {
                int move;
                if (map[i][j].front().d == 1) {
                    move = min(leftMove, tempY - 1);
                    tempY -= move;
                }
                else if (map[i][j].front().d == 2) {
                    move = min(leftMove, r - tempY);
                    tempY += move;
                }
                else if (map[i][j].front().d == 3) {
                    move = min(leftMove, c - tempX);
                    tempX += move;
                }
                else if (map[i][j].front().d == 4) {
                    move = min(leftMove, tempX - 1);
                    tempX -= move;
                }

                if (move != leftMove) map[i][j].front().d = redirection[map[i][j].front().d];
                leftMove -= move;
            }

            map[i][j].front().time++;

            map[tempY][tempX].push_back(map[i][j].front());
            map[i][j].erase(map[i][j].begin() + 0);
        }
    }
}

void deleteOverlappedShark() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (map[i][j].size() <= 1) continue;

            int maxIndex = 0;
            for (int k = 1; k < map[i][j].size(); k++) {
                if(map[i][j][k].z > map[i][j][maxIndex].z) maxIndex = k;
            }

            int maxSize = map[i][j][maxIndex].z;
            int index = 0;
            while (map[i][j].size() != 1) {
                if (map[i][j][index].z == maxSize) index++;
                else map[i][j].erase(map[i][j].begin() + index);
            }
        }
    }
}

void run() {
    while (anglerPos <= c) {
        huntShark();
        moveSharks();
        deleteOverlappedShark();

        anglerPos++;
    }
}

int main() {
    initVar();
    run();

    cout << sumOfSize;
}