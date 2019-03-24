#include <iostream>
using namespace std;

struct Point {
    int y;
    int x;

    Point(){};
    Point(int y, int x) {
        this->y = y;
        this->x = x;
    }
};

struct Redirection {
    int sec;
    int direction;
};

bool isGameEnded(int n, int y, int x) {
    if ((0 <= y) && (n > y) && (0 <= x) && (n > x)) return false;
    return true;
}

int main() {
    int n, k, l;
    cin >> n >> k;

    Point toward[4] = {Point(0, +1), Point(-1, 0),
                          Point(0, -1), Point(+1, 0)};

    Point *appleP = new Point[k];
    for (int i = 0; i < k; i++) {
        cin >> appleP[i].y >> appleP[i].x;
    }

    cin >> l;
    Redirection *redirection = new Redirection[l];
    for (int i = 0; i < l; i++) {
        cin >> redirection[i].sec >> redirection[i].direction;
    }

    int time = 0, direction = 0, redirectionIdx = 0;
    Point curP = Point(0, 0);

    while(true) {
        time++;

        // TODO what if it exceeds the numOfitem?
        if (time == redirection[redirectionIdx].sec) {
            direction = (direction + redirection[redirectionIdx].direction) % 4;
            redirectionIdx++;
        }

        curP.y += toward[direction].y;
        curP.x += toward[direction].x;

        if (isGameEnded(n, curP.y, curP.x)) break;
    }

    cout << time;
}