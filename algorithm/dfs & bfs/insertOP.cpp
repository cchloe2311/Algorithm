#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

#define SUM 0
#define SUB 1
#define MUL 2
#define DIV 3

int n;
int nums[11];
vector<int> ops;
bool visited[11];

int maxResult = -1000000000;
int minResult = 1000000000;

void dfs(int pre, int time, int visitedIdx, int numsIdx) {
//    for (int i = 0; i < n - 1; i++) cout << visited[i] << " ";
//    cout << endl;

//    cout << pre << endl << "###" << endl;

    int result = pre;

    if (time == 0) {
        if (maxResult < result) maxResult = result;
        if (result < minResult) minResult = result;

        visited[visitedIdx] = false;
        return;
    }

    for (int i = 0; i < (n - 1); i++) {
        if(!visited[i]) {
            switch(ops[i]) {
                case SUM:
                    result += nums[numsIdx];
                    break;
                case SUB:
                    result -= nums[numsIdx];
                    break;
                case MUL:
                    result *= nums[numsIdx];
                    break;
                case DIV:
                    result /= nums[numsIdx];
                    break;
            }

            visited[i] = true;
            dfs(result, time - 1, i, numsIdx + 1);
            result = pre;
        }
    }

    visited[visitedIdx] = false;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> nums[i];

    // 0 : +, 1 : -, 2 : x, 3 : %
    for (int i = 0; i < 4; i++) {
        int temp;
        cin >> temp;

        for (int j = 0; j < temp; j++) ops.push_back(i);
    }

    dfs(nums[0], n - 1, 0, 1);

    cout << maxResult << endl << minResult;
}