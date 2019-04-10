#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

#define MAX 16

int n, m, d;

int map[MAX][MAX];
int copiedMap[MAX][MAX];
bool isHit[MAX];

int dy[3] = {0, -1, 0};
int dx[3] = {-1, 0, +1};

queue<vector<int>> shooters;

class Pos {
public:
    int y;
    int x;

    int shooter;

    Pos(int y, int x) {
        this->y = y;
        this->x = x;
    }

    Pos(int y, int x, int shoooter) {
        this->y = y;
        this->x = x;
        this->shooter = shoooter;
    }
};

queue<Pos> arrows;

void resetMapVars() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            copiedMap[i][j] = map[i][j];
        }
    }

    memset(isHit, false, sizeof(bool) * MAX);
}

void moveEnemies() {
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++) {
            if (copiedMap[i][j] == 1) {
                copiedMap[i][j] = 0;
                copiedMap[i + 1][j] = 1;
            }
        }
}

bool isClear() {
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++)
            if (copiedMap[i][j] == 1) return false;

    return true;
}

bool isInRange(int y, int x) {
    if ((y >= 0) && (y < n) && (x >= 0) && (x < m)) return true;
    else return false;
}

int getResult(vector<int> v) {
    vector<Pos> killedEnemies;
    int hit = 0;
    int distance = 0;

    for (int i = 0; i < 3; i++) arrows.push(Pos(n, v[i], v[i]));

    while(!arrows.empty()) {
        int size = arrows.size();

        for (int i = 0; i < size; i++) {
            Pos front = arrows.front();
            arrows.pop();

            for (int j = 0; j < 3; j++) {
                int y = front.y + dy[j];
                int x = front.x + dx[j];

                if (isInRange(y, x) && !isHit[front.shooter]) {
                    if (copiedMap[y][x] == 1) {
                        killedEnemies.push_back(Pos(y, x, front.shooter));
                        isHit[front.shooter] = true;

                        break;
                    }
                    else {
                        arrows.push(Pos(y, x, front.shooter));
                    }
                }
            }
        }

        if ((++distance == d) || (isHit[v[0]] && isHit[v[1]] && isHit[v[2]])) {
            for (int i = 0; i < killedEnemies.size(); i++) {
                if (copiedMap[killedEnemies[i].y][killedEnemies[i].x] == 1) {
                    copiedMap[killedEnemies[i].y][killedEnemies[i].x] = 0;
                    hit++;
                }
            }
            killedEnemies.clear();

            moveEnemies();

            while(!arrows.empty()) arrows.pop();
            if (isClear()) return hit;

            for (int i = 0; i < 3; i++) arrows.push(Pos(n, v[i], v[i]));

            distance = 0;
            memset(isHit, false, sizeof(bool) * m);
        }
    }

    while(!arrows.empty()) arrows.pop();
    return hit;
}

void getShooterPoses(int time) {
    int size = shooters.size();

    for (int i = 0; i < size; i++) {
        vector<int> front = shooters.front();
        shooters.pop();

        for (int j = (front.empty() ? 0 : front.back() + 1); j < m; j++) {
            vector<int> temp(front);
            temp.push_back(j);

            shooters.push(temp);
        }
    }

    if (time == 1) return;
    else getShooterPoses(time - 1);
}

int main() {
    cin >> n >> m >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    shooters.push({});
    getShooterPoses(3);

    int max = -1, temp;

    while(!shooters.empty()) {
        resetMapVars();

        temp = getResult(shooters.front());
        shooters.pop();

        if (temp > max) max = temp;
    }

    cout << max;
}