#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int *dp = new int[n+1];
    dp[0] = 1;
    int num = 1;

    for(int i=1; i<=n; i++){
        int square = num*num;
        if(square == i) num++;
        else square = (num-1)*(num-1);

        dp[i] = dp[square]+dp[i-square];
    }

    cout << dp[n];
}