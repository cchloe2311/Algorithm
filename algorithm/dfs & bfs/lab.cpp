#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

#define EMPTY 0
#define WALL 1
#define VIRUS 2

class Point{
public:
    int y;
    int x;

    Point(int y, int x) {
        this->y = y;
        this->x = x;
    }
};

vector<vector<int>> getWallPoints(vector<vector<int>> orgWalls, int n, int numOfPoints) {
    vector<vector<int>> newWalls;

    if (orgWalls.size() != 0) {
        for (int i = 0; i < orgWalls.size(); i++) {
            for (int j = 0; j < numOfPoints; j++) {
                if (find(orgWalls[i].begin(), orgWalls[i].end(), j) == orgWalls[i].end()) {
                    vector<int> newWall(orgWalls[i]);
                    newWall.push_back(j);

                    sort(newWall.begin(), newWall.end());

                    newWalls.push_back(newWall);
                }
            }
        }
    }
    else {
        for (int j = 0; j < numOfPoints; j++) {
            vector<int> newWall;
            newWall.push_back(j);

            newWalls.push_back(newWall);
        }
    }

    if (n == 1) return newWalls;
    else return getWallPoints(newWalls, --n, numOfPoints);
}

bool isInRange(int y, int x, int n, int m) {
    if ((y >= 0) && (y < n) && (x >= 0) && (x < m)) return true;
    else return false;
}

void getSafeArea(int **map, vector<Point> virusPoints, int &safeArea, int n, int m) {
    int neighbor[4][2] = {{0, +1}, {0, -1}, {+1, 0}, {-1, 0}};

    queue<Point> q;

    for (int i = 0; i < virusPoints.size(); i++) {
        q.push(Point(virusPoints[i].y, virusPoints[i].x));

        while(!q.empty()) {
            Point front = q.front();
            q.pop();

            for (int j = 0; j < 4; j++) {
                int y = front.y + neighbor[j][0];
                int x = front.x + neighbor[j][1];

                if (isInRange(y, x, n, m) && (map[y][x] == EMPTY)) {
                    q.push(Point(y, x));
                    map[y][x] = VIRUS;

                    safeArea--;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int **map = new int*[n];
    vector<Point> emptyPoints;
    vector<Point> virusPoints;

    int orgSafeArea = 0;

    for (int i = 0; i < n; i++) {
        map[i] = new int[m];

        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == EMPTY) {
                emptyPoints.push_back(Point(i, j));
                orgSafeArea++;
            }
            else if (map[i][j] == VIRUS) {
                virusPoints.push_back(Point(i, j));
            }
        }
    }

    vector<vector<int>> wallPoints = getWallPoints({}, 3, emptyPoints.size());

    int maxSafeArea = -1;

    for (int i = 0; i < wallPoints.size(); i++) {
        int **newMap = new int*[n];
        for (int j = 0; j < n; j++) {
            newMap[j] = new int[m];

            for (int k = 0; k < m; k++) newMap[j][k] = map[j][k];
        }

        for (int j = 0; j < 3; j++)
            newMap[emptyPoints[wallPoints[i][j]].y][emptyPoints[wallPoints[i][j]].x] = WALL;

        int safeArea = orgSafeArea - 3;

        getSafeArea(newMap, virusPoints, safeArea, n, m);

        if (safeArea > maxSafeArea) maxSafeArea = safeArea;

        for (int j = 0; j < n; j++) delete [] newMap[j];
        delete [] newMap;
    }

    cout << maxSafeArea;
}