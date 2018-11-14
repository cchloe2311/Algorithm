//#include <iostream>
//#include <string>
//#include <queue>
//#include <utility>
//#include <string.h>
//using namespace std;


//TODO 다른 풀이 방법
//: 사거리는 유닛부터의 x좌표 거리 차, y좌표 거리 차의 합과 같음
//>> 그냥 모든 좌표에 유닛의 x, y좌표 거리 차를 계산해서 넣어두고
//   필요한 값만 출력해주는 방법이 있음 > 훨씬 쉬움


//class RangeInfo{
//public:
//    int y;
//    int x;
//    int distanceFromUnit;
//    RangeInfo(int y, int x, int distanceFromUnit){
//        this->y = y; this->x = x; this->distanceFromUnit = distanceFromUnit;
//    }
//};
//
//bool isInMap(int sizeOfMap, int y, int x){
//    if(y >sizeOfMap || x > sizeOfMap || x <1 || y < 1) return false;
//    else return true;
//}
//
//void printResult(int **map, int sizeOfMap){
//    for(int i=1; i<=sizeOfMap; i++){
//        for(int j=1; j<=sizeOfMap; j++){
//            if(map[i][j] != -1) cout << map[i][j] << " ";
//            else cout << "x ";
//        }
//        cout << endl;
//    }
//}
//
//int main(){
//    int sizeOfMap;
//    cin >> sizeOfMap;
//    int **map = new int*[sizeOfMap+1];
//    for(int i=1; i<=sizeOfMap; i++){
//        map[i] = new int[sizeOfMap+1];
//        memset(map[i], 0, sizeof(int)*(sizeOfMap+1));
//    }
//
//    int y, x, attackRange;
//    cin >> y >> x >> attackRange;
//
//    pair<int, int> adj[4] = {make_pair(0, -1), make_pair(-1, 0),
//                             make_pair(0, +1), make_pair(+1, 0)};
//    queue<RangeInfo> q;
//    q.push(RangeInfo(y, x, 0));
//
//    map[y][x] = -1;
//
//    while(1){
//        RangeInfo temp = q.front();
//        q.pop();
//
//        for(int i=0; i<4; i++){
//            if(!isInMap(sizeOfMap, temp.y+adj[i].first, temp.x+adj[i].second)) continue;
//
//            if(map[temp.y+adj[i].first][temp.x+adj[i].second] == 0){
//                if(temp.distanceFromUnit == attackRange){
//                    printResult(map, sizeOfMap);
//                    return 0;
//                }
//                map[temp.y+adj[i].first][temp.x+adj[i].second] = temp.distanceFromUnit+1;
//                q.push(RangeInfo(temp.y+adj[i].first, temp.x+adj[i].second, temp.distanceFromUnit+1));
//            }
//        }
//    }
//}