//#include <iostream>
//using namespace std;
//
//#define SIZE 10
//
//int main(){
//    int map[SIZE][SIZE];
//    int inout;
//    cin >> inout;
//
//    for(int i=0; i<SIZE; i++)
//        for(int j=0; j<SIZE; j++) cin >> map[i][j];
//
//
//    for(int i=0; i<inout; i++){
//        for(int r=0; r<SIZE; r++)
//            map[i][r] = (map[i][r]+1)%2;
//        for(int c=0; c<SIZE; c++){
//            if(c == i) continue;
//            map[c][i] = (map[c][i]+1)%2;
//        }
//    }
//
//    for(int c=0; c<SIZE; c++){
//        for(int r=0; r<SIZE; r++) cout << map[c][r] << " ";
//        cout << endl;
//    }
//
//}