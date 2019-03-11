#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

#define START 1

int getVirusComputer(vector<int> *graph, int n) {
    stack<int> s;
    int *isVirus = new int[n + 1];
    memset(isVirus, 0, sizeof(int)*(n + 1));

    s.push(START);
    isVirus[START] = 1;

    while (!s.empty()) {
        int top = s.top();
        s.pop();

        for (int i = 0; i < graph[top].size(); i++) {
            int index = graph[top][i];

            if (isVirus[index] == 0) {
                isVirus[index] = 1;
                s.push(index);
            }
        }
    }

    int count = 0;
    for (int i = 2; i < (n + 1); i++) {
        if(isVirus[i] == 1) count++;
    }

    return count;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> *graph = new vector<int>[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << getVirusComputer(graph, n);
}