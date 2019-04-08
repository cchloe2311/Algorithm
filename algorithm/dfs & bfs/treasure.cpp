#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Pos;
int h, w;
int map[50][50];

vector<Pos> v;

int dy[4] = {-1, +1, 0, 0};
int dx[4] = {0, 0, -1, +1};

class Pos {
public:
    int y;
    int x;

    Pos(){}
    Pos(int y, int x) {
        this->y = y;
        this->x = x;
    }
};

bool isInRange(int y, int x) {
    if ((y >= 0) && (y < h) && (x >= 0) && (x < w)) return true;
    else return false;
}

void copyMap(int dest[50][50]) {
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) dest[i][j] = map[i][j];
}

int getDist(int startY, int startX) {
    queue<Pos> q;
    q.push(Pos(startY, startX));

    int copiedMap[50][50];
    copyMap(copiedMap);

    copiedMap[startY][startX] = 0;

    int y, x;
    while(!q.empty()) {
        y = q.front().y;
        x = q.front().x;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int tempY = y + dy[i];
            int tempX = x + dx[i];

            if (isInRange(tempY, tempX) && copiedMap[tempY][tempX] == -1) {
                copiedMap[tempY][tempX] = copiedMap[y][x] + 1;
                q.push(Pos(tempY, tempX));
            }
        }
    }

    return copiedMap[y][x];
}

int getTreasureDist() {
    int maxDist = -1;
    int copiedMap[50][50];

    copyMap(copiedMap);

    for (int i = 0; i < v.size(); i++) {
        if (copiedMap[v[i].y][v[i].x] == -2) continue;

        queue<Pos> q;
        q.push(v[i]);

        copiedMap[v[i].y][v[i].x] = -2;
        int y, x;

        while(!q.empty()) {
            y = q.front().y;
            x = q.front().x;
            q.pop();

            for (int j = 0; j < 4; j++) {
                int tempY = y + dy[j];
                int tempX = x + dx[j];

                if (isInRange(tempY, tempX) && copiedMap[tempY][tempX] == -1) {
                    copiedMap[tempY][tempX] = -2;
                    q.push(Pos(tempY, tempX));
                }
            }
        }

        int tempDist = getDist(y, x);
        if (tempDist > maxDist) maxDist = tempDist;
    }

    return maxDist;
}

int main() {
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < w; j++)
            if (input[j] == 'W') map[i][j] = -2;
            else {
                map[i][j] = -1;
                v.push_back(Pos(i, j));
            }
    }

    cout << getTreasureDist();
}