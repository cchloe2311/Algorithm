#include <iostream>
using namespace std;

#define DIV 1000007

int main(){
    int n;
    cin >> n;

    int *dp = new int[n+1];

    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = (dp[i-2]+dp[i-1])%DIV;
    }

    cout << dp[n];
}