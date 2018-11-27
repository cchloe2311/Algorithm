#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    int n, numOfCase;
    cin >> n >> numOfCase;
    vector<vector<int> > v;
    v.resize(n+1);

    for(int i=0; i<numOfCase; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=0; i<n; i++) sort(v[i].begin(), v[i].end());

    queue<int> q;
    q.push(1);
    int *visited = new int[n+1];
    int numOfVirus = 0;
    memset(visited, 0, sizeof(int)*(n+1));
    visited[1] = 1;
    while(!q.empty()){
        for(int i=0; i<v[q.front()].size(); i++){
            if(visited[v[q.front()][i]] == 0){
                q.push(v[q.front()][i]);
                visited[v[q.front()][i]] = 1;
                numOfVirus++;
            }
        }
        q.pop();
    }

    cout << numOfVirus;
}