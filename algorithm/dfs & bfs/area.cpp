#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dy[4] = {-1, +1, 0, 0};
int dx[4] = {0, 0, -1, +1};

int h, w;
int map[100][100] = { 0, };

class Pos {
public:
    int y;
    int x;

    Pos(int y, int x) {
        this->y = y;
        this->x = x;
    }
};

bool isInRange(int y, int x) {
    if ((y >= 0) && (y < h) && (x >= 0) && (x < w)) return true;
    else return false;
}

vector<int> getResult() {
    vector<int> result;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (map[i][j] != 0) continue;

            queue<Pos> q;
            q.push(Pos(i, j));

            int area = 1;
            map[i][j] = 1;

            int y, x;
            while(!q.empty()) {
                y = q.front().y;
                x = q.front().x;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int tempY = y + dy[k];
                    int tempX = x + dx[k];

                    if (isInRange(tempY, tempX) && map[tempY][tempX] == 0) {
                        map[tempY][tempX] = 1;
                        q.push(Pos(tempY, tempX));

                        area++;
                    }
                }
            }

            result.push_back(area);
        }
    }

    sort(result.begin(), result.end());
    return result;
}

int main() {
    int k;
    cin >> h >> w >> k;

    for (int i = 0; i < k; i++) {
        int ldx, ldy, rux, ruy;
        cin >> ldx >> ldy >> rux >> ruy;

        for (int y = ldy; y < ruy; y++) {
            for (int x = ldx; x < rux; x++) map[y][x] = -1;
        }
    }

    vector<int> result = getResult();

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}