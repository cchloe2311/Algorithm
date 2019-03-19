#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

bool isPossible(vector<int> *graph, int n){
    stack<int> s;
    int *colored = new int[n];
    memset(colored, 0, sizeof(int) * n);

    s.push(0);
    colored[0] = 1;

    while(!s.empty()) {
        int top = s.top();
        s.pop();

        for (int i = 0; i < graph[top].size(); i++) {
            if (colored[graph[top][i]] == colored[top]) {
                return false;
            }
            else if (colored[graph[top][i]] == 0) {
                colored[graph[top][i]] = (colored[top] * -1);
                s.push(graph[top][i]);
            }
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> *graph = new vector<int>[n];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (isPossible(graph, n)) cout << "YES";
    else cout << "NO";
}