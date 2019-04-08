#include <iostream>
#include <queue>
using namespace std;

#define RIPEN 1
#define TOMATO 0

int n, m, h;
int box[100][100][100]; // h, n, m
int numOfTomato;

class Pos {
public:
    int h;
    int n;
    int m;

    Pos(int h, int n, int m) {
        this->h = h;
        this->n = n;
        this->m = m;
    }
};

bool isInRange(int tempH, int tempN, int tempM) {
    if ((tempH < 0) || (tempH >= h)) return false;
    else if ((tempN >= 0) && (tempN < n) && (tempM >= 0) && (tempM < m)) return true;
    else return false;
}

int getTerm(queue<Pos> q, int term) {
    int dh[6] = {-1, 1, 0, 0, 0, 0};
    int dn[6] = {0, 0, +1, -1, 0, 0};
    int dm[6] = {0, 0, 0, 0, +1, -1};

    int size = q.size();
    bool check = false;

    for (int i = 0; i < size; i++) {
        Pos front = q.front();
        q.pop();

        for (int j = 0; j < 6; j++) {
            int tempH = front.h + dh[j];
            int tempN = front.n + dn[j];
            int tempM = front.m + dm[j];

            if (isInRange(tempH, tempN, tempM) && (box[tempH][tempN][tempM] == TOMATO)) {
                q.push(Pos(tempH, tempN, tempM));
                box[tempH][tempN][tempM] = RIPEN;

                check = true;
                numOfTomato--;
            }
        }
    }

//    if (!check && (term == 0)) return -1;
    if (!check && (numOfTomato == 0)) return term;
    else if (!check) return -1;
    else return getTerm(q, ++term);
}

int main() {
    cin >> m >> n >> h;
    queue<Pos> q;

    numOfTomato = 0;

    for (int k = 0; k < h; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> box[k][i][j];

                if (box[k][i][j] == RIPEN) {
                    q.push(Pos(k, i, j));
                }
                else if (box[k][i][j] == TOMATO) {
                    numOfTomato++;
                }
            }

    cout << getTerm(q, 0);
}