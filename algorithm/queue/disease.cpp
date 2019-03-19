#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int *visited = new int[n+1];
    memset(visited, 0, sizeof(int)*(n+1));

    queue<int> q;
    q.push(k);
    visited[k] = 1;

    while(!q.empty()){
        int town = q.front();

        if(town*2 <= n && visited[town*2] == 0){
            visited[town*2] = 1;
            q.push(town*2);
        }

        if(visited[town/3] == 0){
            visited[town/3] = 1;
            q.push(town/3);
        }

        q.pop();
    }

    int notVisited = 0;
    for(int i=1; i<=n; i++)
        if(visited[i] == 0) notVisited++;

    cout << notVisited;
}