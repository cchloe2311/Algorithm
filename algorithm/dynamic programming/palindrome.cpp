#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
    string str;
    cin >> str;

    int strSize = str.size();

    int **table = new int*[strSize];
    for (int i = 0; i < strSize; i++) {
        table[i] = new int[strSize];
        memset(table[i], 0, sizeof(int)*strSize);
    }

    for (int i = 0; i < (strSize-1); i++) {
        int index = 0;
        for (int j = i+1; j < strSize; j++) {
            if(str[index] == str[j]){
                table[index][j] = table[index+1][j-1];
            }
            else{
                table[index][j] = (min(table[index+1][j], table[index][j-1]) + 1);
            }

            index++;
        }
    }

    cout << table[0][strSize-1];
}