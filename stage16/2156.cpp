//
// Created by 최서정 on 2018. 8. 5..
//

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
    int numOfGlass;
    cin >> numOfGlass;
    int *amount = new int[numOfGlass+1];
    long long **d = new long long*[2];
    for(int i=0; i<2; i++){
        d[i] = new long long[numOfGlass+1];
        memset(d[i], 0, sizeof(int)*(numOfGlass+1));
    }
    for(int i=1; i<=numOfGlass; i++) cin >> amount[i];
    long long maxOfPreCol = amount[1];
    long long maxOfPrePart = 0;

    d[0][0] = 0, d[1][0] = 0;
    d[0][1] = amount[1], d[1][1] = 0;
    for(int i=2; i<=numOfGlass; i++){
        d[0][i] = maxOfPrePart + amount[i];
        d[1][i] = d[0][i-1] + amount[i];
        maxOfPrePart = max(maxOfPrePart, maxOfPreCol);
        maxOfPreCol = max(d[0][i], d[1][i]);
    }
    maxOfPrePart = max(maxOfPrePart, maxOfPreCol);
    cout << maxOfPrePart;
}