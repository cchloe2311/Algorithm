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

class Case {
public:
    vector<int> v;
    bool visited[11];

    Case(vector<int> v, bool visited[11]) {
        for (int i = 0; i < v.size(); i++) this->v.push_back(v[i]);
        for (int i = 0; i < 11; i++) this->visited[i] = visited[i];
    }
};

vector<Case> cases;

void getCases(int count) {
    int size = cases.size();

    for (int i = 0; i < size; i++) {
        Case front = cases.front();
        cases.erase(cases.begin());

        for (int j = 0; j < ops.size(); j++) {
            if (!front.visited[j]) {
                Case tempCase(front.v, front.visited);
                tempCase.v.push_back(j);
                tempCase.visited[j] = true;

                cases.push_back(tempCase);
            }
        }
    }

    if (count == 1) return;
    else getCases(count - 1);
}

int calculate(vector<int> v) {
    int result = nums[0];

    cout << nums[0];

    for (int i = 0; i < n - 1; i++) {
        switch (ops[v[i]]) {
            case SUM:
                cout << "+";
                result += nums[i + 1];
                break;
            case SUB:
                cout << "-";
                result -= nums[i + 1];
                break;
            case MUL:
                cout << "×";
                result *= nums[i + 1];
                break;
            case DIV:
                cout << "÷";
                result /= nums[i + 1];
                break;
        }
        cout << nums[i + 1];
    }

    cout << " = " << result;

    cout << endl;
    return result;
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

    bool initVisited[11] = {false};
    cases.push_back(Case({}, initVisited));
    getCases(n - 1);

    int max = -1000000000;
    int min = 1000000000;

    while(!cases.empty()) {
        int temp = calculate(cases.front().v);
        cases.erase(cases.begin());

        if (temp > max) max = temp;
        if (temp < min) min = temp;
    }

    cout << max << endl << min;
}