#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Point {
public:
    int y;
    int x;
    int depth;
    Point(int y, int x, int depth) {
        this->y = y;
        this->x = x;
        this->depth = depth;
    }
};

bool isInRange(int height, int width, int y, int x) {
    if((y >= 0) && (y < height) && (x >= 0) && (x < width)) return true;
    else return false;
}

int getShortestDist(int **map, int height, int width) {
    queue<Point> q;

    int neighbor[4][2] = {{0, +1}, {0, -1}, {+1, 0}, {-1, 0}};

    q.push(Point(height-1, 0, 0));
    map[height-1][0] = 1;

    while(!q.empty()) {
        Point front = q.front();
        q.pop();

        if ((front.y == 0) && (front.x == width - 1)) {
            return front.depth;
        }

        for (int i = 0; i < 4; i++) {
            int y = front.y + neighbor[i][0];
            int x = front.x + neighbor[i][1];

            if (isInRange(height, width, y, x) && (map[y][x] == 0)) {
                q.push(Point(y, x, front.depth + 1));
                map[y][x] = 1;
            }
        }
    }
}

int main() {
    int height, width;
    cin >> height >> width;

    int **map = new int*[height];
    for (int i = 0; i < height; i++) map[i] = new int[width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> map[i][j];
        }
    }

    cout << getShortestDist(map, height, width);
}