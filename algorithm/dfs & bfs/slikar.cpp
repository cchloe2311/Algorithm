#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#define EMPTY 0
#define WATER -1
#define S 1
#define D 2

static int neighbor[4][2] = {{0,  +1},
                             {0,  -1},
                             {+1, 0},
                             {-1, 0}};

int r, c;

class Position {
public:
    int y;
    int x;

    Position(int y, int x) {
        this->y = y;
        this->x = x;
    }
};

bool isInRange(int y, int x) {
    if ((y >= 0) && (y < r) && (x >= 0) && (x < c)) return true;
    else return false;
}

void spreadWater(int **map, vector<Position> &waterV) {
    vector<Position> empty;
    swap(empty, waterV);

    for (int i = 0; i < empty.size(); i++) {
        Position pos = empty[i];

        for (int j = 0; j < 4; j++) {
            int y = pos.y + neighbor[j][0];
            int x = pos.x + neighbor[j][1];

            if (isInRange(y, x) && ((map[y][x] == EMPTY) || (map[y][x] == S))) {
                waterV.push_back(Position(y, x));

                map[y][x] = WATER;
            }
        }
    }
}

void printMap(int **map) {
    cout << endl;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << map[i][j] << " ";
        cout << endl;
    }

    cout << endl;
}

int getResult(int **map, vector<Position> waterV, Position src) {
    int turn = 0;

    int **visited = new int *[r];
    for (int i = 0; i < r; i++) {
        visited[i] = new int[c];
        memset(visited[i], 0, sizeof(int) * c);
    }

    queue<Position> pre;
    pre.push(src);
    visited[src.y][src.x] = 1;

    while (true) {
        printMap(map);
        spreadWater(map, waterV);
        printMap(map);

        bool isMoved = false;
        queue<Position> cur;

        while (!pre.empty()) {
            Position front = pre.front();
            pre.pop();

            for (int i = 0; i < 4; i++) {
                int y = front.y + neighbor[i][0];
                int x = front.x + neighbor[i][1];

                if (isInRange(y, x) && (visited[y][x] == 0)) {
                    if (map[y][x] == D) {
                        return turn;
                    } else if (map[y][x] == EMPTY) {
                        cur.push(Position(y, x));

                        visited[y][x] = 1;
                        isMoved = true;
                    }
                }
            }
        }

        if (!isMoved) return -1;
        else {
            turn++;

//            queue<Position> empty;
            swap(pre, cur);
        }
    }
}


int main() {
    cin >> r >> c;

    map<char, int> m = {{'.', EMPTY},
                        {'*', WATER},
                        {'S', S},
                        {'D', D}};

    int **map = new int *[r];
    vector<Position> waterV;
    Position src(-1, -1);
    Position dest(-1, -1);

    for (int i = 0; i < r; i++) {
        map[i] = new int[c];

        for (int j = 0; j < c; j++) {
            char input;
            cin >> input;

            map[i][j] = m[input];

            if (map[i][j] == WATER) waterV.push_back(Position(i, j));
            else if (map[i][j] == S) {
                src.y = i;
                src.x = j;
            } else if (map[i][j] == D) {
                dest.y = i;
                dest.x = j;
            }
        }
    }

    cout << getResult(map, waterV, src);
}