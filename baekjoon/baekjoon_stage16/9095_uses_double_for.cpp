//
// Created by 최서정 on 2018. 9. 25..
//

#include <iostream>
using namespace std;

int main(){
    int numOfCase;
    cin >> numOfCase;
    int *input = new int[numOfCase];

    for(int i=0; i<numOfCase; i++){
        int n;
        cin >> n;

        int *d = new int[n+1];
        d[0] = 1;
        int index = 0;
        for(int j=1; j<= n; j++){
            if(j >= 3) d[j] = d[j-1] + d[j-2] + d[j-3];
            else if (j == 2) d[j] = d[j-1] + d[j-2];
            else d[j] = d[j-1];
        }
        input[i] = d[n];
    }

    for(int i=0; i<numOfCase; i++) cout << input[i] << endl;
}