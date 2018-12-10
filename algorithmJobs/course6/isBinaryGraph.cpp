#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int *group = new int[n+1];
    memset(group, 0, sizeof(int)*(n+1));

    vector<int> *graph = new vector<int>[n+1];

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    group[1] = 1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(int i=0; i<graph[front].size(); i++){
            if(group[graph[front][i]] == 0){
                group[graph[front][i]] = group[front] * (-1);
                q.push(graph[front][i]);
            }
            else if(group[graph[front][i]] == group[front]){
                cout << "NO";
                return 1;
            }
        }
    }
    cout << "YES";
}