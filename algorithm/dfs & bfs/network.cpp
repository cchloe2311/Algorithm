#include <string>
#include <vector>

#define MAX 200

using namespace std;

int visited[MAX] = {0};

void visitConnectedPC(int index, vector<vector<int>> computers) {
    visited[index] = 1;

    for (int i = 0; i < computers.size(); i++) {
        if ((computers[index][i] == 1) && (visited[i] == 0)) visitConnectedPC(i, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) continue;

        answer++;
        visitConnectedPC(i, computers);
    }

    return answer;
}