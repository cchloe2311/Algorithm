#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string.h>
#include <iostream>

#define MAX 20001
#define NOT_DEFINED -1

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    int depthArr[MAX];
    memset(depthArr, NOT_DEFINED, sizeof(depthArr));
    depthArr[1] = 0;

    queue<int> q;
    q.push(1);

    map<int, vector<int>> map;
    for (int i = 0; i < n; i++) {
        map.insert({i + 1, {}});
    }

    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];

        (*map.find(a)).second.push_back(b);
        (*map.find(b)).second.push_back(a);
    }

    int maxDepth = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < (*map.find(node)).second.size(); i++) {
            if (depthArr[(*map.find(node)).second[i]] == NOT_DEFINED) {
                depthArr[(*map.find(node)).second[i]] = depthArr[node] + 1;
                q.push((*map.find(node)).second[i]);

                if ((depthArr[node] + 1) > maxDepth) maxDepth = depthArr[node] + 1;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (depthArr[i + 1] == maxDepth) answer++;
    }

    return answer;
}

int main() {
    cout << solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
}