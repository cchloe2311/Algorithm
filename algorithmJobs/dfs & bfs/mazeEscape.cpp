#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Position {
public:
    int y;
    int x;
    int depth;
    int crushed;

    Position(int y, int x, int depth, int crushed);
};

Position::Position(int y, int x, int depth, int crushed) {
    this->y = y;
    this->x = x;
    this->depth = depth;
    this->crushed = crushed;
}

bool isInRange(int n, int m, int y, int x) {
    if ((y >=0) && (y < n) && (x >= 0) && (x < m)) return true;
    else return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    static int goalY = 0;
    static int goalX = m - 1;

    int **map = new int*[n];
    for (int i = 0; i < n; i++) {
        map[i] = new int[m];
    }

    int **visited = new int*[n];
    for (int i = 0; i < n; i++) {
        visited[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    pair<int, int> neighbor[4] = {{0, +1}, {-1, 0}, {0, -1}, {+1, 0}};

    queue<Position> q;
    Position initP = Position(n - 1, 0, 0, 0);
    q.push(initP);
    visited[n - 1][0] = 1;

    while(!q.empty()) {
        Position p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int neighborY = p.y + neighbor[i].first;
            int neighborX = p.x + neighbor[i].second;

            if ((neighborY == goalY) && (neighborX == goalX)) {
                cout << (p.depth + 1);
                return 0;
            }

            if (!isInRange(n, m, neighborY, neighborX)) continue;

            Position neighborP = Position(neighborY, neighborX,
                                          (p.depth + 1), (p.crushed + map[neighborY][neighborX]));

            if ((visited[neighborY][neighborX] != 1) && (neighborP.crushed == 0)) {
                visited[neighborY][neighborX] = 1;
                q.push(neighborP);
            }
            else if ((visited[neighborY][neighborX] == 0) && (neighborP.crushed == 1)) {
                visited[neighborY][neighborX] = 2;
                q.push(neighborP);
            }
        }
    }
}