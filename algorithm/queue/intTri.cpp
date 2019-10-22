#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    queue<int> q;

    int left, right;

    for (int i = 0; i < triangle.size(); i++) {
        left = 0;
        cout << i + 1 << endl;

        int size = q.size();

        for (int j = 0; j < triangle[i].size(); j++) {
            if (size > 0) {
                right = q.front();
                q.pop();
                size--;
            } else right = 0;

            cout << triangle[i][j] + max(left, right) << "\t";

            q.push(triangle[i][j] + max(left, right));
            left = right;
        }

        cout << endl;
    }

    while (!q.empty()) {
        if (answer < q.front()) answer = q.front();
        q.pop();
    }

    return answer;
}

int main() {
    cout << solution(
            {
                    {7},
                    {3, 8},
                    {8, 1, 0},
                    {2, 7, 4, 4},
                    {4, 5, 2, 6, 5}
            }
    );
}