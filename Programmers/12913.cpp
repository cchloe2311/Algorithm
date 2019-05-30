#include <iostream>

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/12913
int solution(vector<vector<int> > land)
{
    int answer = 0;

    vector<vector<int>> dp;
    dp.push_back({0, 0, 0, 0});

    for (int i = 0; i < land.size(); i++) {
        int max[4] = {0};

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (j == k) continue;
                if (max[j] < dp.back()[k]) max[j] = dp.back()[k];
            }
        }

        dp.push_back({max[0] + land[i][0], max[1] + land[i][1],
                      max[2] + land[i][2], max[3] + land[i][3]});
    }

    answer = *max_element(dp.back().begin(), dp.back().end());

    return answer;
}

int main() {
    vector<vector<int>> land = {
            {1, 2, 3, 5},
            {5, 6, 7, 8},
            {4, 3, 2, 1}
    };

    cout << solution(land);
}