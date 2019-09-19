#include <iostream>
#include <limits.h>
#include <stack>
#include <string.h>
#include <utility>
using namespace std;

#define MAX_SIZE 500001
#define MAX_HEIGHT 100000001

int towers[MAX_SIZE];
int n;

stack<pair<int, int>> s;

void initVar() {
    memset(towers, 0, MAX_SIZE);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> towers[i];
    }

    while(!s.empty()) s.pop();
    s.push({MAX_HEIGHT, 0});
}

void getRes() {
    for (int i = 0; i < n; i++) {
        while (s.top().first < towers[i]) {
            s.pop();
        }
        int temp = towers[i];
        towers[i] = s.top().second;
        s.push({temp, i + 1});
    }
}

int main() {
    initVar();
    getRes();

    for (int i = 0; i < n; i++) {
        cout << towers[i] << " ";
    }
}