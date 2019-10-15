#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

#define MAX 100
using namespace std;

int r = 3, c = 3;
int turn = 0;
int arr[MAX][MAX] = {0,};
int targetR, targetC, goal;

class Element {
public:
    int num;
    int count;

    Element(int num, int value) {
        this->num = num;
        this->count = value;
    }
};

bool isDone() {
    return (arr[targetR - 1][targetC - 1] == goal);
}

void initVar() {
    cin >> targetR >> targetC >> goal;

    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cin >> arr[i][j];
    }

    r = 3, c = 3;
    turn = 0;
}

bool sortingCmp(const Element &a, const Element &b) {
    if (a.count != b.count) return a.count < b.count;
    else return a.num < b.num;
}

int findNum(vector<Element> v, int num) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].num == num) return i;
    }
    return -1;
}

void rowSorting() {
    int maxCol = 0;

    for (int i = 0; i < r; i++) {
        vector<Element> v;
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == 0) continue;

            int index = findNum(v, arr[i][j]);
            if (index != -1) v[index].count++;
            else v.push_back(Element(arr[i][j], 1));

            arr[i][j] = 0;
        }
        sort(v.begin(), v.end(), sortingCmp);

        int tempCol = 0;
        for (int j = 0; j < v.size(); j++) {
            if (j == 50) break;
            arr[i][2 * j] = v[j].num;
            arr[i][2 * j + 1] = v[j].count;
            tempCol = 2 * j + 1 + 1;
        }

        if (maxCol < tempCol) maxCol = tempCol;
    }

    c = maxCol;
}

void colSorting() {
    int maxRow = 0;

    for (int i = 0; i < c; i++) {
        vector<Element> v;
        for (int j = 0; j < r; j++) {
            if (arr[j][i] == 0) continue;

            int index = findNum(v, arr[j][i]);
            if (index != -1) v[index].count++;
            else v.push_back(Element(arr[j][i], 1));

            arr[j][i] = 0;
        }
        sort(v.begin(), v.end(), sortingCmp);

        int tempRow = 0;
        for (int j = 0; j < v.size(); j++) {
            if (j == 50) break;
            arr[2 * j][i] = v[j].num;
            arr[2 * j + 1][i] = v[j].count;
            tempRow = 2 * j + 1 + 1;
        }

        if (maxRow < tempRow) maxRow = tempRow;
    }

    r = maxRow;
}

void printArr() {
    cout << "#" << turn << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << arr[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

int main() {
    initVar();

    while(!isDone()) {
        if (turn > MAX) {
            turn = -1;
            break;
        }

        if (r >= c) rowSorting();
        else colSorting();

        turn++;

//        printArr();
    }

    cout << turn;
}