#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <limits.h>
#include <string.h>
using namespace std;

#define CHICKEN 2
#define HOME 1

int n, m;
bool check[14] = {false};

class Pos;
vector<Pos> homeV;
vector<Pos> chickenV;

class Pos {
public:
    int y;
    int x;

    vector<int> distToChicken;

    Pos(int y, int x) {
        this->y = y;
        this->x = x;
    }
};

int getSumOfDist() {
    int sum = 0;

    for (int i = 0; i < homeV.size(); i++) {
        int part = INT_MAX;

        for (int j = 0; j < chickenV.size(); j++) {
            if (check[j] && (homeV[i].distToChicken[j] < part)) part = homeV[i].distToChicken[j];
        }
        sum += part;
    }

    return sum;
}

int getMinDist() {
    queue<vector<int>> q;
    q.push({});

    int minDist = INT_MAX;

    while (!q.empty()) {
        vector<int> front = q.front();
        q.pop();

        for (int i = (front.empty() ? 0 : front.back() + 1); i < chickenV.size(); i++) {
            vector<int> temp(front);
            temp.push_back(i);

            if (temp.size() <= m) {
                memset(check, false, sizeof(bool) * 14);
                for (int j = 0; j < temp.size(); j++) {
                    check[temp[j]] = true;
                }

                int tempDist = getSumOfDist();
                if (tempDist < minDist) minDist = tempDist;

                q.push(temp);
            }
        }
    }

    return minDist;
}

int main() {
    cin >> n >> m;

    int **map = new int*[n];
    for (int i = 0; i < n; i++) {
        map[i] = new int[n];

        for (int j = 0; j < n; j++) {
            cin >> map[i][j];

            if (map[i][j] == HOME) homeV.push_back(Pos(i, j));
            else if (map[i][j] == CHICKEN) chickenV.push_back(Pos(i, j));
        }
    }

    for (int i = 0; i < homeV.size(); i++) {
        for (int j = 0; j < chickenV.size(); j++) {
            homeV[i].distToChicken
            .push_back(abs(chickenV[j].y - homeV[i].y) + abs(chickenV[j].x - homeV[i].x));
        }
    }

    if (m >= chickenV.size()) {
        memset(check, true, sizeof(bool) * 14);

        cout << getSumOfDist();
    }
    else {
        cout << getMinDist();
    }

}