//#include <iostream>
//#include <string.h>
//using namespace std;
//
//int main(){
//    int c, r; // 가로 세로
//    cin >> c >> r;
//
//    int **frame = new int*[r];
//    for(int i=0; i<r; i++) frame[i] = new int[c];
//    int *maxHOfCol = new int[c];
//    for(int i=0; i<c; i++) maxHOfCol[i] = -1;
//
//    for(int i=r-1; i>=0; i--){ // 세로
//        for(int j=0; j<c; j++){ // 가로
//            cin >> frame[i][j];
//            if(frame[i][j] == 1)
//                if(maxHOfCol[j] == -1) maxHOfCol[j] = i;
//        }
//    }
//    int minIndex = 0;
//    for(int i=1; i<c; i++)
//        if(maxHOfCol[minIndex] > maxHOfCol[i]) minIndex = i;
//
//    int startRow =  maxHOfCol[minIndex]+1;
//    if(r-startRow < 4) {
//        cout << 0 << " "<< 0;
//        return 0;
//    }
//    int score = 0;
//    for(int i=startRow; i < r; i++){
//        int check = 0;
//        for(int j=0; j<c; j++){
//            if(frame[i][j] == 1) check ++;
//            else if(j == minIndex) check ++;
//            else break;
//        }
//        if(check == c) score++;
//    }
//    if(score == 0) cout << 0 << " " << score;
//    else cout << minIndex+1 << " " << score;
//}