//
// Created by 최서정 on 2018. 10. 14..
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define SIZE 500

int main(){
    int input[SIZE][SIZE*2] = {0,};
    int output[SIZE][SIZE*2] = {0,};
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int index = n-i;
        for(int j=0; j<=i; j++){
            cin >> input[i][index];
            index +=2;
        }
    }

    output[0][n] = input[0][n];
    for(int i=1; i<n; i++){
        int index = n-i;
        for(int j=0; j<=i; j++){
            output[i][index] = max(output[i-1][index-1], output[i-1][index+1]) + input[i][index];
            index +=2;
        }
    }
    cout << *max_element(output[n-1], output[n-1]+n*2);
}