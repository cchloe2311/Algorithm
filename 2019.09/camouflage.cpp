#include <string>
#include <vector>
#include <algorithm>
#include <utility>

#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    vector<pair<string, int>> v;
    int numOfCategory = 0;

    for (int i = 0; i < clothes.size(); i++) {
        bool flag = false;
        for(auto iter = v.begin(); iter < v.end(); iter++) {
            if ((*iter).first == clothes[i][1]) {
                (*iter).second++;
                flag = true;
                break;
            }
        }

        if (!flag) {
            v.push_back({clothes[i][1], 1});
            numOfCategory++;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        answer *= (v[i].second + 1);
    }

    return answer - 1;
}

int main() {
    cout << solution({{"yellow_hat", "headgear"}, {"blue", "22"}, {"green_turban", "headgear"}});
}