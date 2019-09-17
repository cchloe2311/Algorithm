#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    vector<pair<string, int>> v;
    int numOfCategory = 0;

    queue<vector<int>> indexQ;
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

            indexQ.push({numOfCategory});
            numOfCategory++;
        }
    }

    while (!indexQ.empty()) {
        vector<int> index = indexQ.front();
        indexQ.pop();

        int value = 1;
        for (int i = 0; i < index.size(); i++) {
            value *= v[index[i]].second;
        }
        answer += value;

        for (int i = index.back() + 1; i < numOfCategory; i++) {
            index.push_back(i);
            indexQ.push(index);

            index.pop_back();
        }
    }

    return answer;
}

int main() {
    cout << solution({{"yellow_hat", "headgear"}, {"blue", "headgear"}, {"green_turban", "headgear"}});
}