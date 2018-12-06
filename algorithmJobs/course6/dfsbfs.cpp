#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

bool isLeft(int *visited, int n){
    for(int i=0; i<n; i++)
        if(visited[i] == 0) return true;
    return false;
}

int findPath(vector<int> graph, int *visited){
    for(int i=0; i<graph.size(); i++){
        if(visited[graph[i]] == 0) return graph[i];
    }
    return -1;
}

void dfs(vector<int> *graph, int n){
    int *visited = new int[n];
    memset(visited, 0, sizeof(int)*n);

    visited[0] = 1;
    stack<int> s;
    s.push(0);
    cout << 0 << " ";

    while(isLeft(visited, n)){
        int path = findPath(graph[s.top()], visited);
        if(path == -1) s.pop();
        else{
            visited[path] = 1;
            cout << path << " ";
            s.push(path);
        }
    }
}

void bfs(vector<int> *graph, int n){
    int *visited = new int[n];
    memset(visited, 0, sizeof(int)*n);

    visited[0] = 1;
    queue<int> q;
    q.push(0);
    cout << 0 << " ";

    while(isLeft(visited, n)){
        int path = q.front();
        q.pop();

        for(int i=0; i<graph[path].size(); i++)
            if(visited[graph[path][i]] == 0){
                visited[graph[path][i]] = 1;
                cout << graph[path][i] << " ";
                q.push(graph[path][i]);
            }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> *graph = new vector<int>[n];
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=0; i<n; i++) sort(graph[i].begin(), graph[i].end());

    dfs(graph, n);
    cout << endl;
    bfs(graph, n);
}