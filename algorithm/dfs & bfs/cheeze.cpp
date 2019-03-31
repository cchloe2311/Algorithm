#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define AIR 0
#define CHEEZE 1
#define MELTED -1

class Position{
public:
    int y;
    int x;
    Position(int y, int x) {
        this->y = y;
        this->x = x;
    }
};

bool isInRange(int y, int x, int h, int w) {
    if ((y >= 0) && (y < h) && (x >= 0) && (x < w)) return true;
    else return false;
}

pair<vector<Position>, int> bfs(vector<Position> pre, int **map, int count, int h, int w) {
    vector<Position> cur;

    int neighbor[4][2] = {{0, +1}, {0, -1}, {+1, 0}, {-1, 0}};

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << map[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;


    for (int i = 0; i < pre.size(); i++) {
        for (int j = 0; j < 4; j++) {
            int y = pre[i].y + neighbor[j][0];
            int x = pre[i].x + neighbor[j][1];

            if (isInRange(y, x, h, w) && (map[y][x] == CHEEZE)) {
                map[y][x] = MELTED;
                cur.push_back(Position(y, x));
            }
        }
    }

    if (cur.empty()) return {pre, count - 1};
    else return bfs(cur, map, ++count, h, w);
}

int main() {
    int h, w;
    cin >> h >>w;

    int **map = new int*[h];
    vector<Position> airPos;

    for (int i = 0; i < h; i++) {
        map[i] = new int[w];

        for (int j = 0; j < w; j++) {
            cin >> map[i][j];

            if (map[i][j] == AIR) {
                airPos.push_back(Position(i, j));
            }
        }
    }

    pair<vector<Position>, int> result = bfs(airPos, map, 1, h, w);

    cout << result.second << endl << result.first.size();
}