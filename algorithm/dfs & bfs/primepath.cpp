#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <utility>
using namespace std;

bool isPrimeNum(int num) {
    for (int i = 2; (i*i) <= num; i++) {
        if ((num % i) == 0) return false;
    }

    return true;
}

int getPrimepath(string src, string dest) {
    int visited[10000] = {0};

    queue<pair<string, int>> q;
    q.push({src, 0});
    visited[stoi(src)] = 1;

    if (src == dest) return 0;

    while(!q.empty()) {
        string front = q.front().first;
        int depth = q.front().second;

        q.pop();

        string temp = front;
        int tempNum;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 10; j++) {
                temp[i] = j + '0';
                tempNum = stoi(temp);

                if (temp == dest) return (depth + 1);
                else if ((temp >= "1000") && (visited[tempNum] == 0) && isPrimeNum(tempNum)) {
                    q.push({temp, depth + 1});
                    visited[tempNum] = 1;
                }
            }
            temp = front;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> paths;
    for (int i = 0; i < n; i++) {
        string src, dest;
        cin >> src >> dest;

        paths.push_back(getPrimepath(src, dest));
    }

    for (int i = 0; i < n; i++) cout << paths[i] << endl;
}