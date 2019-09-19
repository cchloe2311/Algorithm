#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX_SIZE 26
#define VISIT 2

using namespace std;

int map[MAX_SIZE][MAX_SIZE];
int n;
int size = 0;

int dy[4] = {0, 0, +1, -1};
int dx[4] = {+1, -1, 0, 0};

void initVar() {
    cin >> n;
    memset(map, 0, sizeof(map));
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        for (int j = 0; j < n; j++) map[i][j] = (temp[j] - '0');
    }
}

bool isInRange(int y, int x) {
    if (y >= 0 && y < n && x >= 0 && x < n) return true;
    else return false;
}

void numberComplex(int posY, int posX) {
    map[posY][posX] = VISIT;
    size++;

    for (int i = 0; i < 4; i++) {
        int tempY = posY + dy[i];
        int tempX = posX + dx[i];

        if (isInRange(tempY, tempX) && (map[tempY][tempX] == 1)) {
            numberComplex(tempY, tempX);
        }
    }
}

int main() {
    vector<int> res;
    int numOfComplex = 0;

    initVar();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
                size = 0;
                numberComplex(i, j);

                res.push_back(size);
                numOfComplex++;
            }
        }
    }

    sort(res.begin(), res.end());

    cout << numOfComplex << endl;
    for (int i = 0; i < numOfComplex; i++) {
        cout << res[i] << endl;
    }
}