//
// Created by 최서정 on 2018. 7. 31..
//

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    int *score = new int[n+1];
    long long **d = new long long*[2];
    for(int i=0; i<2; i++){
        d[i] = new long long[n+1];
        memset(d[i], 0, sizeof(int)*(n+1));
    }
    for(int i=1; i<=n; i++) cin >> score[i];
    d[0][1] = score[1];

    for(int i=2; i<=n; i++){
        d[0][i] = max(d[0][i-2], d[1][i-2]) + score[i];
        d[1][i] = d[0][i-1] + score[i];
    }
    cout << max(d[0][n], d[1][n]);
}