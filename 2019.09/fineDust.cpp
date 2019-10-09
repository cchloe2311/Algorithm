#include <iostream>
#include <queue>
#include <utility>

#define MAX_SIZE 60
#define TURN 1
#define AIR_CLEANER -1

using namespace std;

pair<int, int> map[MAX_SIZE][MAX_SIZE];
int row, col;
int timeInput;

int dy[4] = {0, 0, +1, -1};
int dx[4] = {+1, -1, 0, 0};

queue<pair<int, int>> upperWind;
queue<pair<int, int>> lowerWind;

void printMap() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) cout << map[i][j].first << "\t";
        cout << endl;
    }

    cout << endl;
}

void initUpperWind(int index) {
    int curRow = index;
    for (int i = 1; i < col; i++) upperWind.push({curRow, i});
    for (curRow -= 1; curRow >= 0; curRow--) upperWind.push({curRow, col - 1});
    curRow = 0;
    for (int i = col - 2; i >= 0; i--) upperWind.push({curRow, i});
    for (curRow += 1; curRow <= index; curRow++) upperWind.push({curRow, 0});
}
void initLowerWind(int index) {
    int curRow = index;
    for (int i = 1; i < col; i++) lowerWind.push({curRow, i});
    for (curRow += 1; curRow < row; curRow++) lowerWind.push({curRow, col - 1});
    curRow = row - 1;
    for (int i = col - 2; i >= 0; i--) lowerWind.push({curRow, i});
    for (curRow -= 1; curRow >= index; curRow--) lowerWind.push({curRow, 0});
}

void runAirCleaner(queue<pair<int, int>> q) {
    int value = 0;

    while (true) {
        if (map[q.front().first][q.front().second].first == AIR_CLEANER) break;

        int temp = value;
        value = map[q.front().first][q.front().second].first;
        map[q.front().first][q.front().second].first = temp;

        q.pop();
    }
}

void initVar() {
    while (!upperWind.empty()) upperWind.pop();
    while (!lowerWind.empty()) lowerWind.pop();

    cin >> row >> col >> timeInput;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> map[i][j].first;
            map[i][j].second = 0;

            if (map[i][j].first == AIR_CLEANER) {
                if (upperWind.empty()) initUpperWind(i);
                else initLowerWind(i);
            }
        }
    }
}

bool canSpread(int y, int x) {
    if ((y < 0) || (y >= row) || (x < 0) || (x >= col)) return false;
    else return map[y][x].first != AIR_CLEANER;
}

void run() {
    while(--timeInput >= 0) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if ((map[i][j].first == 0) || map[i][j].first == AIR_CLEANER) continue;

                int spreadNeighbor = 0;

                for (int p = 0; p < 4; p++) {
                    int y = i + dy[p];
                    int x = j + dx[p];

                    if (!canSpread(y, x)) continue;

                    spreadNeighbor++;
                    map[y][x].second += (int) (map[i][j].first / 5);
                }

                map[i][j].first -= (spreadNeighbor * (map[i][j].first / 5));
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                map[i][j].first += map[i][j].second;
                map[i][j].second = 0;
            }
        }

        runAirCleaner(upperWind);
        runAirCleaner(lowerWind);
    }
}

int getNumOfFineDust() {
    int res = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) res += map[i][j].first;
    }

    return res;
}

int main() {
    for (int i = 0; i < TURN; i++) {
        initVar();
        run();

        cout << getNumOfFineDust() + 2;
    }
}