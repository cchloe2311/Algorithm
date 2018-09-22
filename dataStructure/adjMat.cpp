//
// Created by 최서정 on 2018. 9. 22..
//

#include <iostream>
#include <string.h> // memset 함수 사용을 위해
using namespace std;

int main(){
    int numOfNode;
    int numOfEdge;
    cin >> numOfNode >> numOfEdge;

    int **mat = new int*[numOfNode];
    for(int i=0; i<numOfNode; i++){
        mat[i] = new int[numOfNode];
        memset(mat[i], 0, sizeof(int)*numOfNode); // 메모리 공간을 0으로 초기
    }

    for(int i=0; i<numOfEdge; i++){
        int x, y;
        cin >> x >> y;
        mat[x][y] = 1;
        mat[y][x] = 1;
    }
}