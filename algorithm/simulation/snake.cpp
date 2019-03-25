#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int y;
    int x;

    Point(){};
    Point(int y, int x) {
        this->y = y;
        this->x = x;
    }

    bool operator==(const Point& rhs) {
        if ((this->y==rhs.y) && (this->x==rhs.x)) return true;
        else return false;
    }
};

struct Redirection {
    int sec;
    int direction;
};

bool isGameEnded(int n, int y, int x) {
    if ((0 < y) && (n >= y) && (0 < x) && (n >= x)) return false;
    return true;
}

int main() {
    int n, k, l;
    cin >> n >> k;

    Point toward[4] = {Point(0, +1), Point(+1, 0),
                          Point(0, -1), Point(-1, 0)};

    vector<Point> appleP;
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;

        appleP.push_back(Point(y, x));
    }

    cin >> l;
    Redirection *redirection = new Redirection[l];
    for (int i = 0; i < l; i++) {
        char direction;

        cin >> redirection[i].sec >> direction;

        if (direction == 'D') redirection[i].direction = +1;
        else redirection[i].direction = -1;
    }

    int time = 0, direction = 0, redirectionIdx = 0;
    Point curP = Point(1, 1);

    // TODO 뱀이 자신의 몸에 부딫힌 경우!
    // TODO 문제 이해 // 첫번째 예제의 답이 9인 이유를 모르겠음ㅜ

    while(true) {
        time++;

        curP.y += toward[direction].y;
        curP.x += toward[direction].x;

        if ((redirectionIdx < l) && (time == redirection[redirectionIdx].sec)) {
            direction = (direction + redirection[redirectionIdx].direction) % 4;
            redirectionIdx++;
        }

        auto it = find(appleP.begin(), appleP.end(), Point(curP.y, curP.x));
        if (it != appleP.end()) {
            curP.y += toward[direction].y;
            curP.x += toward[direction].x;

            appleP.erase(it);
        }

        if (isGameEnded(n, curP.y, curP.x)) break;
    }

    cout << time;
}