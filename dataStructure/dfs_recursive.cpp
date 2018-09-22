//
// Created by 최서정 on 2018. 9. 22..
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int> *adj, bool *visited, int v){
    cout << v << " ";
    visited[v] = true;

    for(int i=0; i<adj[v].size(); i++){
        if(!visited[adj[v][i]]){
            v = adj[v][i];
            dfs(adj, visited, v);
        }
    }
}

int main(){
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> adj[n+1]; // 1번부터 N번까지

    bool *visited = new bool[n+1];
    memset(visited, false, sizeof(bool)*(n+1));

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    } // 인접리스트 생성

    for(int i=0; i<n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(adj, visited, v);
}