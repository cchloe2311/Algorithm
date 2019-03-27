#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define SIZE 16
#define NUM_OF_CASE 10

void inputMap(int map[SIZE][SIZE], int posInfo[2][2]) {
    for (int i = 0; i < SIZE; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < SIZE; j++) {
            map[i][j] = input[j] - '0';

            if (map[i][j] == 2) {
                posInfo[0][0] = i;
                posInfo[0][1] = j;
            }
            else if (map[i][j] == 3) {
                posInfo[1][0] = i;
                posInfo[1][1] = j;
            }
        }
    }
}

bool isInRange(int y, int x) {
    if ((y >= 0) && (y < SIZE) && (x >= 0) && (x < SIZE)) return true;
    else return false;
}

bool isPossible(int map[SIZE][SIZE],  int posInfo[2][2]) {
    int neighbor[4][2] = {{0, +1}, {0, -1}, {+1, 0}, {-1, 0}};

    queue<pair<int, int>> q;

    q.push({posInfo[0][0], posInfo[0][1]});
    map[posInfo[0][0]][posInfo[0][1]] = -1;

    while(!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int y = front.first + neighbor[i][0];
            int x = front.second + neighbor[i][1];

            if ((y == posInfo[1][0]) && (x == posInfo[1][1])) return true;
            if (isInRange(y, x) && (map[y][x] == 0)) {
                q.push({y, x});
                map[y][x] = -1;
            }
        }
    }

    return false;
}

int main() {
    int result[NUM_OF_CASE][2];

    for (int i = 0; i < NUM_OF_CASE; i++) {
        int map[SIZE][SIZE] = { 0, };
        int posInfo[2][2];
        int caseId;

        cin >> caseId;
        result[i][0] = caseId;
        inputMap(map, posInfo);

        if (isPossible(map, posInfo)) result[i][1] = 1;
        else result[i][1] = 0;
    }

    for (int i = 0; i < NUM_OF_CASE; i++) {
        cout << "#" << result[i][0] << " " << result[i][1] << endl;
    }
}