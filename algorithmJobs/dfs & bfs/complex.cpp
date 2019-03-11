#include <iostream>
#include <string.h>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>
#include <stdlib.h>

using namespace std;

bool isInRange(int n, int y, int x) {
    if (y >= 0 && y < n && x >= 0 && x < n) return true;
    else return false;
}

int getNumOfHouse(int **map, int n, int y, int x) {
    pair<int, int> neighbor[4] = {{-1, 0}, {0, -1},
                                  {+1, 0}, {0, +1}};

    stack<pair<int, int> > s;

    int count = 0;

    s.push({y, x});
    map[y][x] = -1;
    count++;

    while (!s.empty()) {
        pair<int, int> top = s.top();

        for (int i = 0; i < 4; i++) {
            int yPos = top.first + neighbor[i].first;
            int xPos = top.second + neighbor[i].second;

            if (isInRange(n, yPos, xPos) && (map[yPos][xPos] == 1)) {
                s.push({yPos, xPos});
                map[yPos][xPos] = -1;
                count++;

                break;
            }

            if (i == 3) {
                s.pop();
            }
        }
    }

    return count;
}

int main() {
    vector<int> complex;

    int n;
    cin >> n;

    int **map =  new int*[n];
    for (int i = 0; i < n; i++) {
        map[i] = new int[n];

        string input;
        cin >> input;

        for (int j = 0; j < n; j++) {
            map[i][j] = atoi(input.substr(j, 1).c_str());
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
                complex.push_back(getNumOfHouse(map, n, i, j));
            }
        }
    }

    sort(complex.begin(), complex.end());

    cout << complex.size() << endl;

    for (int i = 0; i < complex.size(); i++) {
        cout << complex[i] << endl;
    }

}