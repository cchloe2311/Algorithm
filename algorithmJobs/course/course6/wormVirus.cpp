#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int main(){
    int c, e;
    cin >> c >> e;

    vector<int> *graph = new vector<int>[c+1];

    int *visited = new int[c+1];
    memset(visited, 0, sizeof(int)*(c+1));

    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while(!q.empty()){
        int path = q.front();
        q.pop();
        for(int i=0; i<graph[path].size(); i++){
            if(visited[graph[path][i]] == 0){
                q.push(graph[path][i]);
                visited[graph[path][i]] = 1;
            }
        }
    }

    int numOfVirus = 0;
    for(int i=2; i<c+1; i++)
        if(visited[i] == 1) numOfVirus++;

    cout << numOfVirus;
}