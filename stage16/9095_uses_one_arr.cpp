//
// Created by 최서정 on 2018. 9. 25..
//

#include <iostream>
#include <limits.h> // for INT_MIN
using namespace std;

int main(){
    int numOfCase;
    cin >> numOfCase;
    int *input = new int[numOfCase];
    int maxCase = INT_MIN;
    for(int i=0; i<numOfCase; i++){
        cin >> input[i];
        if(input[i] > maxCase) maxCase = input[i];
    }

    int *d = new int[maxCase+1];
    d[0] = 1;
    int index = 0;
    for(int i=1; i<= maxCase; i++){
        if(i >= 3) d[i] = d[i-1] + d[i-2] + d[i-3];
        else if (i == 2) d[i] = d[i-1] + d[i-2];
        else d[i] = d[i-1];
    }

    for(int i=0; i<numOfCase; i++)
        cout << d[input[i]] << endl;
}