#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> candidate[20];
int dp[16] = { 0 };

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int t, p;
        cin >> t >> p;

        candidate[i + t - 1].push_back({i - 1, p});
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];

        int max = dp[i];
        for (int j = 0; j <candidate[i].size(); j++) {
            int first = candidate[i][j].first;
            int second = candidate[i][j].second;

            int temp = dp[candidate[i][j].first] + candidate[i][j].second;
            if (temp > max) max = temp;
        }
        dp[i] = max;
    }

    cout << dp[n];
}