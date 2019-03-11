#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

bool isPossible(vector<int> *graph, int n){
    stack<int> s;
    int *group = new int[n + 1];
    memset(group, 0, sizeof(int) * (n + 1));

    s.push(1);
    group[1] = 1;

    while(!s.empty()) {
        int top = s.top();
        s.pop();

        for (int i = 0; i < graph[top].size(); i++) {
            if (group[graph[top][i]] == group[top]) {
                return false;
            }
            else if (group[graph[top][i]] == 0) {
                group[graph[top][i]] = (group[top] * -1);
                s.push(graph[top][i]);

//                break;
            }
//            else if (i == (graph[top].size() - 1)) {
//                s.pop();
//            }
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> *graph = new vector<int>[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (isPossible(graph, n)) cout << "Yes";
    else cout << "No";
}