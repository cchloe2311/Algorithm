#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> getPermutation(vector<vector<int>> pre, int n, int r) {
    vector<vector<int>> present;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < pre.size(); j++) {
            if (find(pre[j].begin(), pre[j].end(), i) == pre[j].end()) {
                vector<int> newCase;

                if (pre[j][0] != -1) newCase = pre[j];
                newCase.push_back(i);

                present.push_back(newCase);
            }
        }
    }

    if (r == 1) return present;
    else return getPermutation(present, n, --r);
}

int main() {
    int n, r;
    cin >> n >> r;

    vector<vector<int>> pre;
    vector<int> initV = {-1};
    pre.push_back(initV);

    vector<vector<int>> permutation = getPermutation(pre, n, r);
    sort(permutation.begin(), permutation.end());

    for (int i = 0; i < permutation.size(); i++) {
        for (int j = 0; j < r; j++) {
            cout << (char)(97 + permutation[i][j]);
        }

        cout << endl;
    }
}