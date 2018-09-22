//
// Created by 최서정 on 2018. 9. 22..
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // for sort
#include <string.h> // for memset
using namespace std;
// 양방향 간선

void dfs(vector<int> *adj, int n,int v){
    stack<int> s;
    s.push(v);
    cout << v << " ";
    bool *visited = new bool[n+1];
    memset(visited, false, sizeof(bool)*(n+1)); // fill과 비교해보기
    visited[v] = true;

    while(!s.empty()){
        int flag = 0;
        for(int i=0; i<adj[v].size(); i++){
            if(!visited[adj[v][i]]){ // 0. 즉, 가본적없는 노드라면,
                v = adj[v][i];
                cout << v << " ";
                s.push(v);
                visited[v] = 1;
                flag = 1;
                break;
            }
        }
        if((flag != 1) && !s.empty()){
            v = s.top();
            s.pop();
        }
    }
}

int main(){
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> adj[n+1]; // 1번부터 N번까지

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    } // 인접리스트 생성

    for(int i=0; i<n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(adj, n, v);
}