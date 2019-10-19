#include <iostream>
#include <queue>

#define MAX_SIZE 20
using namespace std;

int n;

int dy[4] = {0, -1, 0, +1};
int dx[4] = {-1, 0, +1, 0};
int startY[4], startX[4];
int endY[4], endX[4];

int maxValue = 0;

class Cell {
public:
    int value;
    bool check;

    Cell() {
        value = 0;
        check = false;
    }
};

Cell board[MAX_SIZE][MAX_SIZE];

void initVar() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j].value;
        }
    }

    startY[0] = 0;
    startY[1] = 0;
    startY[2] = 0;
    startY[3] = n - 1;

    startX[0] = 0;
    startX[1] = 0;
    startX[2] = n - 1;
    startX[3] = 0;

    endY[0] = n - 1;
    endY[1] = n - 1;
    endY[2] = n - 1;
    endY[3] = 0;

    endX[0] = n - 1;
    endX[1] = n - 1;
    endX[2] = 0;
    endX[3] = n - 1;
}

void shift(int index) {
    queue<Cell> q;

    switch (index) {
        case 0:
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < n; x++) {
                    if (board[y][x].value != 0) {
                        q.push(board[y][x]);
                        board[y][x].value = 0;
                        board[y][x].check = false;
                    }
                }

                int x = 0;
                while (!q.empty()) {
                    if (board[y][x].value == 0) {
                        board[y][x].value = q.front().value;
                        board[y][x].check = false;

                        q.pop();
                    }
                    else if (board[y][x].value == q.front().value && !board[y][x].check) {
                        board[y][x].value *= 2;
                        board[y][x].check = true;

                        q.pop();
                        x++;
                    }
                    else x++;
                }
            }
            break;
        case 1: // 오른쪽
            for (int y = 0; y < n; y++) {
                for (int x = n - 1; x >= 0; x--) {
                    if (board[y][x].value != 0) {
                        q.push(board[y][x]);
                        board[y][x].value = 0;
                        board[y][x].check = false;
                    }
                }

                int x = n - 1;
                while (!q.empty()) {
                    if (board[y][x].value == 0) {
                        board[y][x].value = q.front().value;
                        board[y][x].check = false;

                        q.pop();
                    }
                    else if (board[y][x].value == q.front().value && !board[y][x].check) {
                        board[y][x].value *= 2;
                        board[y][x].check = true;

                        q.pop();
                        x--;
                    }
                    else x--;
                }
            }
            break;
        case 2: // 위쪽
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (board[y][x].value != 0) {
                        q.push(board[y][x]);
                        board[y][x].value = 0;
                        board[y][x].check = false;
                    }
                }

                int y = 0;
                while (!q.empty()) {
                    if (board[y][x].value == 0) {
                        board[y][x].value = q.front().value;
                        board[y][x].check = false;

                        q.pop();
                    }
                    else if (board[y][x].value == q.front().value && !board[y][x].check) {
                        board[y][x].value *= 2;
                        board[y][x].check = true;

                        q.pop();
                        y++;
                    }
                    else y++;
                }
            }
            break;
        case 3:
            for (int x = 0; x < n; x++) {
                for (int y = n - 1; y >= 0; y--) {
                    if (board[y][x].value != 0) {
                        q.push(board[y][x]);
                        board[y][x].value = 0;
                        board[y][x].check = false;
                    }
                }

                int y = n - 1;
                while (!q.empty()) {
                    if (board[y][x].value == 0) {
                        board[y][x].value = q.front().value;
                        board[y][x].check = false;

                        q.pop();
                    }
                    else if (board[y][x].value == q.front().value && !board[y][x].check) {
                        board[y][x].value *= 2;
                        board[y][x].check = true;

                        q.pop();
                        y--;
                    }
                    else y--;
                }
            }
            break;
    }
}

void getMax() {
    int tempValue = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tempValue < board[i][j].value) tempValue = board[i][j].value;
        }
    }

    if (maxValue < tempValue) maxValue = tempValue;
}

void printBoard(int count) {
    cout << endl << "#" << count << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << board[i][j].value << "\t";
        cout << endl;
    }
}

void dfs(int count) {
//    printBoard(count);
    if (count == 5) {
        getMax();
        return;
    }

    Cell tempBoard[MAX_SIZE][MAX_SIZE];
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) tempBoard[y][x] = board[y][x];
    }

    for (int i = 0; i < 4; i++) {
        shift(i);
        dfs(count + 1);

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) board[y][x] = tempBoard[y][x];
        }
    }
}

int main() {
    initVar();
    dfs(0);

    cout << maxValue;
}