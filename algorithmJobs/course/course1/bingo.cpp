//#include <iostream>
//using namespace std;
//
//#define DONE 3
//int numOfline =0;
//
//bool isDone(int frame[5][5], int i, int j){
//    // 해당 좌표가 속한 행, 열을 확인하며 한 줄을 완성했는지 확인 + 대각성분도 확인
//    int check = 0;
//    for(int k=0; k<5; k++)
//        if(frame[i][k] == -1) check++;
//    if(check == 5) numOfline++;
//
//    check = 0;
//    for(int k=0; k<5; k++)
//        if(frame[k][j] == -1) check++;
//    if(check == 5) numOfline++;
//
//    check = 0;
//    if(i == j){
//        for(int k=0; k<5; k++)
//            if(frame[k][k] == -1) check++;
//        if(check == 5) numOfline++;
//    }
//
//    check = 0;
//    if(i+j == 4){
//        for(int k=0; k<5; k++)
//            if(frame[k][4-k] == -1) check++;
//        if(check == 5) numOfline++;
//    }
//
//    if(numOfline >= DONE) return true;
//    else return false;
//}
//
//bool findNum(int frame[5][5], int num){
//    for(int i=0; i<5; i++)
//        for(int j=0; j<5; j++)
//            if(frame[i][j] == num){
//                frame[i][j] = -1;
//                return isDone(frame, i, j);
//            }
//}
//
//int main(){
//    int frame[5][5];
//    for(int i=0; i<5; i++)
//        for(int j=0; j<5; j++) cin >> frame[i][j];
//
//    for(int i=0; i<25; i++){
//        int num;
//        cin >> num;
//        if(findNum(frame, num)){
//            cout << i+1;
//            return 0;
//        }
//    }
//}