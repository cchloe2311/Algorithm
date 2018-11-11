//
// Created by 최서정 on 2018. 9. 25..
//

#include <iostream>
#define MOD 10007
using namespace std;

int main(){
    int n;
    cin >> n;
    int *d = new int[n+1];
    d[0] = 1;
    d[1] = d[0];
    if(n != 1)
        for(int i=2; i<=n; i++)
            d[i] = (d[i-1] + 2*d[i-2])%MOD;
    cout << d[n];
}