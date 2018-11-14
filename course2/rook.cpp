//#include <iostream>
//#include <utility>
//#include <queue>
//using namespace std;
//
//#define SIZE 8
//
//int main(){
//    int map[SIZE][SIZE];
//    vector<pair<int, int> > rooks;
//    for(int i=0; i<SIZE; i++)
//        for(int j=0; j<SIZE; j++){
//            cin >> map[i][j];
//            if(map[i][j] == 2){
//                rooks.push_back(make_pair(i, j));
//            }
//        }
//
//    for(int i=0; i<rooks.size(); i++){
//        int rookY = rooks[i].first;
//        int rookX = rooks[i].second;
//
//        int isDetected = 0;
//        for(int r=0; r<SIZE; r++){
//            if((map[r][rookX] == 1 || map[r][rookX] == 2) && isDetected == 0){
//                isDetected = map[r][rookX];
//            }
//            else if(map[r][rookX] == 3 && (isDetected == 1 || isDetected == 2)) break;
//            else if(map[r][rookX] == 1 && isDetected == 2){
//                cout << 1; return 0;
//            }
//            else if(map[r][rookX] == 2 && isDetected == 1){
//                cout << 1; return 0;
//            }
//        }
//
//        isDetected = 0;
//        for(int c=0; c<SIZE; c++){
//            if((map[rookY][c] == 1 || map[rookY][c] == 2) && isDetected == 0){
//                isDetected = map[rookY][c];
//            }
//            else if(map[rookY][c] == 3 && (isDetected == 1 || isDetected == 2)) break;
//            else if(map[rookY][c] == 1 && isDetected == 2){
//                cout << 1; return 0;
//            }
//            else if(map[rookY][c] == 2 && isDetected == 1){
//                cout << 1; return 0;
//            }
//        }
//    }
//
//    cout << 0;
//}