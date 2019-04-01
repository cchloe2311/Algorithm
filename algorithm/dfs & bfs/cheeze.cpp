#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
using namespace std;

#define AIR 0
#define CHEEZE 1

int neighbor[4][2] = {{0, +1}, {0, -1}, {+1, 0}, {-1, 0}};

int h, w;

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
    if ((y >= 0) && (y < h) && (x >= 0) && (x < w)) return true;
    else return false;
}

vector<Position> getAirArea(int **map) {
    vector<Position> airV;
    queue<Position> airQ;

    int **visited = new int*[h];
    for (int i = 0; i < h; i++) {
        visited[i] = new int[w];
        memset(visited[i], 0, sizeof(int) * w);
    }

    for (int i = 0; i < w; i++) {
        if ((map[0][i] == AIR) && (visited[0][i] == 0)) {
            airQ.push(Position(0, i));
            airV.push_back(Position(0, i));

            visited[0][i] = 1;
        }

        if ((map[h - 1][i] == AIR) && (visited[h - 1][i] == 0)) {
            airQ.push(Position(h - 1, i));
            airV.push_back(Position(h - 1, i));

            visited[h - 1][i] = 1;
        }
    }

    for (int i = 0; i < h; i++) {
        if ((map[i][0] == AIR) && (visited[i][0] == 0)) {
            airQ.push(Position(i, 0));
            airV.push_back(Position(i, 0));

            visited[i][0] = 1;
        }

        if ((map[i][w - 1] == AIR) && (visited[i][w - 1] == 0)) {
            airQ.push(Position(i, w - 1));
            airV.push_back(Position(i, w - 1));

            visited[i][w - 1] = 1;
        }
    }

    while(!airQ.empty()) {
        Position front = airQ.front();
        airQ.pop();

        for (int j = 0; j < 4; j++) {
            int y = front.y + neighbor[j][0];
            int x = front.x + neighbor[j][1];

            if (isInRange(y, x) && (map[y][x] == AIR) && (visited[y][x] == 0)) {
                airQ.push(Position(y, x));
                airV.push_back(Position(y, x));

                visited[y][x] = 1;
            }
        }
    }

    return airV;
}

pair<int, int> getResult(int **map) {
    int turn = 0;
    int preCheeze = 0;

    while(true) {
        bool isDone = true;
        int numOfCheeze = 0;
        vector<Position> airV = getAirArea(map);

        for (int i = 0; i < airV.size(); i++) {
            Position tempP = airV[i];

            for (int j = 0; j < 4; j++) {
                int y = tempP.y + neighbor[j][0];
                int x = tempP.x + neighbor[j][1];

                if (isInRange(y, x) && (map[y][x] == CHEEZE)) {
                    map[y][x] = AIR;
                    isDone = false;

                    numOfCheeze++;
                }
            }
        }

        if (isDone) {
            return {turn, preCheeze};
        }
        else {
            turn++;
            preCheeze = numOfCheeze;
        }
    }
}

int main() {
    cin >> h >> w;

    int **map = new int*[h];
    for (int i = 0; i < h; i++) {
        map[i] = new int[w];

        for (int j = 0; j < w; j++) {
            cin >> map[i][j];
        }
    }

    pair<int, int> result = getResult(map);

    cout << result.first << endl << result.second;
}