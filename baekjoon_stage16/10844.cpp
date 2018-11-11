////
//// Created by 최서정 on 2018. 7. 27..
////

#include <iostream>
using namespace std;

#define MOD 1000000000

int main(){
    long long factor[2][10] = { 0, };

    factor[0][0] = 1;
    factor[0][9] = 1;

    int n;
    cin >> n;
    long long *d = new long long[n+1];
    d[1] = 9;

    for(int i=2; i<=n; i++){
        int indexSrc =  i%2;
        int indexDest = (i+1)%2;
        long long sumOfFactor = 0;
        for(int j=0; j<10; j++){
            if((j-1)>=0) factor[indexDest][j-1] = (factor[indexDest][j-1] + factor[indexSrc][j])%MOD;
            if((j+1)<=9) factor[indexDest][j+1] = (factor[indexDest][j+1] + factor[indexSrc][j])%MOD;
        }
        factor[indexSrc][0] = 0;
        for(int j=1; j<10; j++) {
            sumOfFactor = (sumOfFactor + factor[indexSrc][j])%MOD;
            factor[indexSrc][j] = 0;
        }
        d[i] = d[i-1] - sumOfFactor;
        if(d[i] < 0) d[i] += MOD;
        d[i] = (d[i]*2 + sumOfFactor)%MOD;
    }
    cout << d[n]%MOD;
}