#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

#define INIT_FOOD 5

int n, m, k;

class Ground {
public:
    vector<int> trees;
    int food;
    vector<int> deadTrees;

    Ground() {
        food = INIT_FOOD;
    }
};

Ground farm[11][11];
int foods[11][11];
int newTrees[11][11];

int dy[8] = {-1, -1, -1, 0, 0, +1, +1, +1};
int dx[8] = {-1, 0, +1, -1, +1, -1, 0, +1};

bool isInRange(int y, int x) {
    if ((y > 0) && (y <= n) && (x > 0) && (x <= n)) return true;
    else return false;
}

void spring() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sort(farm[i][j].trees.begin(), farm[i][j].trees.end());

            int index = 0;

            while((index < farm[i][j].trees.size()) && (farm[i][j].trees[index] <= farm[i][j].food)) {
                farm[i][j].food -= farm[i][j].trees[index];
                farm[i][j].trees[index]++;

                index++;
            }

            while(index < farm[i][j].trees.size()) {
                farm[i][j].deadTrees.push_back(farm[i][j].trees[index]);
                farm[i][j].trees.erase(farm[i][j].trees.begin() + index);
            }
        }
    }
}

void summer() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < farm[i][j].deadTrees.size(); k++)
                farm[i][j].food += (farm[i][j].deadTrees[k] / 2);

            farm[i][j].deadTrees.clear();
        }
    }
}

void fall() {
    for (int i = 1; i <= n; i++) memset(newTrees[i], 0, sizeof(int) * 11);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < farm[i][j].trees.size(); k++) {
                if (farm[i][j].trees[k] % 5 != 0) continue;

                for (int l = 0; l < 8; l++) {
                    int y = i + dy[l];
                    int x = j + dx[l];

                    if (isInRange(y, x)) newTrees[y][x]++;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < newTrees[i][j]; k++) {
                farm[i][j].trees.insert(farm[i][j].trees.begin(), 1);
            }
        }
    }
}

void winter() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            farm[i][j].food += foods[i][j];
        }
    }
}

int getAliveTree() {
    int count = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            count += farm[i][j].trees.size();
        }
    }

    return count;
}

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> foods[i][j];
    }

    for (int i = 0; i < m; i++) {
        int y, x, age;
        cin >> y >> x >> age;

        farm[y][x].trees.push_back(age);
    }

    for (int i = 1; i <= k; i++) {
        spring();
        summer();
        fall();
        winter();
    }

    cout << getAliveTree();
}