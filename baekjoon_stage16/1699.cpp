//
// Created by 최서정 on 2018. 9. 26..
//
#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int d[100001] = {0,};
    d[0] = 0;

    for(long long i=1; i<=n; i++){
        d[i] = 100001;
        long long j=i;
        while(1){
            if(j*j <= i) break;
            j--;
        }
        for(j; j>0; j--)
            if(d[i-j*j]+1 < d[i]) d[i] = d[i-j*j]+1;
    }
    printf("%d",d[n]);
}