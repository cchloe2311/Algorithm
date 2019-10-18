#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <math.h>

#define MAX 20
using namespace std;

int n;
int s[MAX][MAX];

void initVar() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> s[i][j];
}

int getSum(vector<int> team) {
    vector<int> index;
    for (int i = 0; i < team.size() - 2; i++) index.push_back(0);
    for (int i = 0; i < 2; i++) index.push_back(1);

    int sum = 0;

    do {
        int player[2];
        int playerIndex = 0;
        for (int i = 0; i < team.size(); i++) {
            if (index[i] == 1) player[playerIndex++] = team[i];
        }

        sum += s[player[0]][player[1]];
        sum += s[player[1]][player[0]];
    } while (next_permutation(index.begin(), index.end()));

    return sum;
}

int run() {
    vector<int> v;
    for (int i = 0; i < n/2; i++) v.push_back(0);
    for (int i = 0; i < n/2; i++) v.push_back(1);

    int minDiff = INT_MAX;

    do {
        vector<int> teams[2];

        for (int i = 0; i < n; i++) teams[v[i]].push_back(i);

        int diff = abs(getSum(teams[0]) - getSum(teams[1]));
        if (minDiff > diff) minDiff = diff;
    } while (next_permutation(v.begin(), v.end()));

    return minDiff;
}

int main() {
    initVar();
    cout << run();
}