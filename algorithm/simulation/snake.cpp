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

bool isGameEnded(int n, Point cur) {
//    if ((cur ))
}

int main() {
    int n, k, l;
    cin >> n >> k;

    Point toward[4] = {Point(0, +1), Point(-1, 0),
                          Point(0, -1), Point(+1, 0)};

    int direction = 0;

    Point *appleP = new Point[k];
    for (int i = 0; i < k; i++) {
        cin >> appleP[i].y >> appleP[i].x;
    }

    cin >> l;
    Redirection *redirection = new Redirection[l];
    for (int i = 0; i < l; i++) {
        cin >> redirection[i].sec >> redirection[i].direction;
    }

    int time = 0;

    while(true) {

    }
}