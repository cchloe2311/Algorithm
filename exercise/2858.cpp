//
// Created by 최서정 on 2018. 10. 1..
//

#include <iostream>
using namespace std;
#define MIN 3

void isMatch(int l, int w, int r){
    if(r == (2*l + 2*w -4)){
        printf("%d %d", l, w);
        exit(1);
    }
}

void underN(int n, int amount, int r){
    for(int i=MIN; i<n; i++)
        if(n*i == amount){
            isMatch(n, i, r);
        }
}
void overN(int n, int amount, int r){
    int m = n+1;
    while(n*m <= amount){
        if(n*m == amount){
            isMatch(m, n, r);
        }
        else if(n*m > amount) return;
        m++;
    }
}

int main(){
    int r, b, l;
    scanf("%d", &r);
    scanf("%d", &b);
    l = MIN;
    int amount = r+b;

    while(1){
        if(l*l > amount) underN(l, amount, r);
        else if(l*l < amount) overN(l, amount, r);
        else isMatch(l, l, r);
    }
}