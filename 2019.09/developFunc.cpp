#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

vector<int> getPossibleReleaseDay(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for (int i = 0; i < progresses.size(); i++) {
        answer.push_back(
                (int) ceil((100.0 - (double) progresses[i]) / (double) speeds[i])
        );
    }

    return answer;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> releaseDay = getPossibleReleaseDay(progresses, speeds);

    int day = -1;

    for (int i = 0; i < progresses.size(); i++) {
        if (day < releaseDay[i]) {
            day = releaseDay[i];
            answer.push_back(1);
        }
        else answer.back()++;
    }

    return answer;
}

int main() {
    vector<int> answer = solution({0}, {0});

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}