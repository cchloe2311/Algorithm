#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i <commands.size(); i++) {
        vector<int> temp(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        sort(temp.begin(), temp.end());

        answer.push_back(temp[commands[i][2] - 1]);
    }

    return answer;
}

int main() {
    vector<int> temp = solution({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}});
    for (int i = 0;i < temp.size(); i++) {
        cout << temp[i]<< endl;
    }
}