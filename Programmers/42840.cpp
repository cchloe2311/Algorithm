#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42840
vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int pattern[3][10] = {
            {1, 2, 3, 4, 5},
            {2, 1, 2, 3, 2, 4, 2, 5},
            {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    int size[3] = {5, 8, 10};
    int correct[3] = {0};

    for (int i = 0; i < answers.size(); i++) {
        for (int j = 0; j < 3; j++) {
            if (pattern[j][i % size[j]] == answers[i]) correct[j]++;
        }
    }

    int max = *max_element(correct, correct + 3);
    for (int i = 0;i < 3; i++) {
        if (correct[i] == max) answer.push_back(i + 1);
    }

    return answer;
}