#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    long long *dp = new long long[n + 1];
    memset(dp, 0, sizeof(long long) * (n + 1));
    dp[0] = 1;
    long long num = 1;

    for(int i=1; i<=n; i++){
        long long square = num*num;

        if(square == i) num++;
        else square = (num-1)*(num-1);

        long long minValue = dp[1 * 1]+dp[i- 1 * 1];
        for (int j = 2; j < num; j++) {
            minValue = min(minValue, dp[j * j]+dp[i- j * j]);
        }

        dp[i] = minValue;
    }

    cout << dp[n];
}