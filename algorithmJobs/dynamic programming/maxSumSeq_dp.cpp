#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    int n, sum = 0;
    cin >> n;

    int input;
    int max = INT_MIN;

    for(int i=0; i<n; i++){
        cin >> input;

        if(sum < 0) sum = input;
        else sum += input;

        if(sum > max) max = sum;
    }

    cout << max;
}