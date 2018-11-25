#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#include <algorithm>
using namespace std;

void bfs(vector<int> *adj, int n, int v){
    queue<int> q;
    bool *visited = new bool[n+1];
    memset(visited, false, sizeof(bool)*(n+1));
    visited[v] = true;
    q.push(v);

    while(!q.empty()){
        v = q.front();
        cout << v << " ";
        q.pop();
        for(int i=0; i<adj[v].size(); i++)
            if(!visited[adj[v][i]]) {
                visited[adj[v][i]] = true;
                q.push(adj[v][i]);
            }
    }
}

void dfs(vector<int> *adj, int n,int v){
    stack<int> s;
    s.push(v);
    cout << v << " ";
    bool *visited = new bool[n+1];
    memset(visited, false, sizeof(bool)*(n+1)); // fill과 비교해보기
    visited[v] = true;

    while(1){
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
            if(i == adj[v].size()-1) s.pop();
        }
        if(s.empty()) break;
        else if((flag != 1) && !s.empty()){
            v = s.top();
            //s.pop();
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

    for(int i=1; i<n+1; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(adj, n, v);
    cout << endl;
    bfs(adj, n, v);
}