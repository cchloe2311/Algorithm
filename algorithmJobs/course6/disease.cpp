#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int main(){
    int n, k;
    cin >> n>> k;

    int *isVisited = new int[n+1];
    memset(isVisited, 0, sizeof(int)*(n+1));
    queue<int> q;
    q.push(k);
    isVisited[k] = 1;

    while(!q.empty()){
        int village = q.front();
        q.pop();

        if(village*2 <= n && isVisited[village*2] == 0){
            q.push(village*2);
            isVisited[village*2] = 1;
        }
        if(village%3 == 0 && isVisited[village/3] == 0){
            q.push(village/3);
            isVisited[village/3] = 1;
        }
    }

    int count = 0;
    for(int i=1; i<=n; i++)
        if(isVisited[i] == 0) count++;

    cout << count;
}