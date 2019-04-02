#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

#define NUM 26

int r, c;

class Position {
public:
    int y;
    int x;
    int depth;
    int visited[4];

    Position(int y, int x, int depth) {
        this->y = y;
        this->x = x;
        this->depth = depth;
        memset(this->visited, false, sizeof(bool) * 4);
    }
};

bool isInRange(int y, int x) {
    if ((y >= 0) && (y < r) && (x >= 0) && (x < c)) return true;
    else return false;
}

int getResult(int **map) {
    int neighbor[4][2] = {{0, +1}, {-1, 0}, {0, -1}, {+1, 0}};

    stack<Position> s;

    bool alphaVisited[NUM] = {false};
    alphaVisited[map[0][0]] = true;
    s.push(Position(0, 0, 1));

    int result = 1;

    while(!s.empty()) {
        Position top = s.top();
        bool isDone = true;

        for (int i = 0; i < 4; i++) {
            int y = top.y + neighbor[i][0];
            int x = top.x + neighbor[i][1];

            int depth = top.depth + 1;

            if (isInRange(y, x) && (!top.visited[i]) && (!alphaVisited[map[y][x]])) {
                s.top().visited[i] = true;
                alphaVisited[map[y][x]] = true;
                s.push(Position(y, x, depth));

                isDone = false;

                if (result < depth) result = depth;
                break;
            }
        }

        if (isDone) {
            s.pop();
            alphaVisited[map[top.y][top.x]] = false;
        }
    }

    return result;
}

int main() {
    cin >> r >> c;

    string *input = new string[r];
    int **map = new int*[r];

    for (int i = 0; i < r; i++) {
        cin >> input[i];

        map[i] = new int[c];
        for (int j = 0; j < c; j++) {
            map[i][j] = input[i][j] - 'A';
        }
    }

    cout << getResult(map);
}