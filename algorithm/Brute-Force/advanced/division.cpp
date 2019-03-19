#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getCases(vector<vector<int>> *precases, int value, int goal) {
    for (int i = 0; i < value; i++) {
        for (int j = 0; j < precases[i].size(); j++) {
            vector<int> newCase = precases[i][j];
            newCase.push_back(value - i);

            sort(newCase.begin(), newCase.end(), greater<int> ());

            if (find(precases[value].begin(), precases[value].end(), newCase) == precases[value].end()) {
                precases[value].push_back(newCase);
            }
        }
    }

    if(value == goal) return;
    else getCases(precases, ++value, goal);
}

int main() {
    int goal;
    cin >> goal;

    vector<vector<int>> *cases = new vector<vector<int>>[goal + 1];
    vector<int> initV = {0};
    cases[0].push_back(initV);

    getCases(cases, 1, goal);

    // goal = goal + 0인 경우를 삭제
    cases[goal].erase(cases[goal].begin());

    for (int i = 0; i < cases[goal].size(); i++) {
        for (int j = 0; j < cases[goal][i].size(); j++) {
            int part = cases[goal][i][j];

            if ((part != 0) && (part != goal)) {
                cout << part;

                if(j != (cases[goal][i].size() - 2)) cout << "+";
                else break;
            }
        }
        cout << endl;
    }

    cout << cases[goal].size();
}