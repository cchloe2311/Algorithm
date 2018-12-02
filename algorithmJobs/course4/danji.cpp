//#include <iostream>
//#include <vector>
//#include <string.h>
//#include <queue>
//#include <utility>
//#include <stdlib.h>
//#include <algorithm>
//using namespace std;
//
//bool isInRange(int y, int x, int size){
//    if(y < 0 || x < 0 || y >=size || x >= size) return false;
//    else return true;
//}
//
//void defineDanji(int** map, int **visited, int y, int x, int danjiSeq, int size){
//    queue<pair<int, int> > q;
//    q.push(make_pair(y, x));
//    visited[y][x] = danjiSeq;
//
//    int neighbor[4][2] = {{0, -1}, {-1, 0}, {0, +1}, {+1, 0}};
//
//    while(!q.empty()){
//        y = q.front().first;
//        x = q.front().second;
//        q.pop();
//
//        for(int i=0; i<4; i++){
//            int neighborY = y + neighbor[i][0];
//            int neighborX = x + neighbor[i][1];
//            if(!isInRange(neighborY, neighborX, size)) continue;
//
//            if(visited[neighborY][neighborX] == 0 && map[neighborY][neighborX] == 1){
//                visited[neighborY][neighborX] = danjiSeq;
//                q.push(make_pair(neighborY, neighborX));
//            }
//        }
//    }
//}
//
//int main(){
//    int n;
//    cin >> n;
//    int **map = new int*[n];
//    int **visited = new int*[n];
//    for(int i=0; i<n; i++){
//        map[i] = new int[n];
//        visited[i] = new int[n];
//        memset(visited[i], 0, sizeof(int)*n);
//    }
//
//    for(int i=0; i<n; i++){
//        string line;
//        cin >> line;
//        for(int j=0; j<n; j++) map[i][j] = atoi(line.substr(j, 1).c_str());
//    }
//
//    int numOfDanji = 0;
//    int curPointY = 0, curPointX = 0;
//    while(curPointY != (n-1) || curPointX != (n-1)){
//        if(map[curPointY][curPointX] == 1 && visited[curPointY][curPointX] == 0){
//            numOfDanji++;
//            defineDanji(map, visited, curPointY, curPointX, numOfDanji, n);
//        }
//        else{
//            if(curPointX == n-1){
//                curPointX = 0;
//                curPointY++;
//            }
//            else{
//                curPointX++;
//            }
//        }
//    }
//
//    int *result = new int[numOfDanji+1];
//    memset(result, 0, sizeof(int)*(numOfDanji+1));
//    for(int i=0; i<n; i++)
//        for(int j=0; j<n; j++) result[visited[i][j]]++;
//
//    sort(result+1, result+numOfDanji+1);
//
//    cout << numOfDanji << endl;
//    for(int i=1; i<=numOfDanji; i++) cout << result[i]<< endl;
//}