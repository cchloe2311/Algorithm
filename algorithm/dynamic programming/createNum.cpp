#include <iostream>
#include <string.h>
using namespace std;

#define DIV 1000007

int main(){
    int n;
    cin >> n;

    int *dp = new int[n+1];
    memset(dp, 0, sizeof(int)*(n+1));
    dp[0] = 1;

    for(int i=1; i<=n; i++){
        int sum = 0;

        sum += dp[i-1];
        if(i-2 >= 0) sum += dp[i-2];
        if(i-3 >=0) sum += dp[i-3];

        sum %= DIV;

        dp[i] = sum;
    }

    cout << dp[n];
}