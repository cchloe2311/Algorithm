//
// Created by 최서정 on 2018. 9. 22..
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int numOfNode;
    int numOfEdge;
    cin >> numOfNode >> numOfEdge;

    vector<int> adj[numOfNode];

    for(int i=0; i<numOfEdge; i++){
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}