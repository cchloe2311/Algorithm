//#include <iostream>
//#include <utility>
//#include <string.h>
//using namespace std;
//
//int main(){
//    int frame[102][102] = {0,};
//    int numOfCase;
//    cin >> numOfCase;
//    int *result = new int[numOfCase+1];
//    memset(result, 0, sizeof(int)*(numOfCase+1));
//
//    for(int i=0; i<numOfCase; i++){
//        int x, y, width, height;
//        cin >> x >> y >> width >> height;
//        for(int r=0; r<height; r++)
//            for(int c=0; c<width; c++) frame[y+r][x+c] = i+1;
//    }
//
//    for(int i=0; i<102; i++)
//        for(int j=0; j<102; j++) result[frame[i][j]]++;
//
//    for(int i=0; i<numOfCase; i++) cout << result[i+1] << endl;
//}