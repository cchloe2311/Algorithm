//#include <iostream>
//#include <vector>
//#include <queue>
//#include <string.h>
//using namespace std;
//
//bool isLeft(int *visited, int n){
//    for(int i=0; i<n; i++)
//        if(visited[i] == 0) return true;
//    return false;
//}
//
//int main(){
//    int n, m;
//    cin >> n >> m;
//    vector<int> *graph = new vector<int>[n];
//    for(int i=0; i<m; i++){
//        int a, b;
//        cin >> a >> b;
//        graph[a].push_back(b);
//        graph[b].push_back(a);
//    }
//
//    int *visited = new int[n];
//    memset(visited, 0, sizeof(int)*n);
//    //int visited[9] = {0};
//
//    queue<int> q[2];
//    q[0].push(0);
//    visited[0] = 1; // color1
//    int turn = 0;
//
//    while(isLeft(visited, n)){
//        while(!q[turn%2].empty()){
//            for(int i=0; i<graph[q[turn%2].front()].size(); i++){
//                if(visited[graph[q[turn%2].front()][i]] == 0){
//                    visited[graph[q[turn%2].front()][i]] = visited[q[turn%2].front()]%2+1;
//                    q[(turn+1)%2].push(graph[q[turn%2].front()][i]);
//                }
//                else if(visited[graph[q[turn%2].front()][i]] != visited[q[turn%2].front()]%2+1){
//                    cout << "NO";
//                    return 1;
//                }
//            }
//            q[turn%2].pop();
//        }
//        turn++;
//    }
//
//    cout << "YES";
//}