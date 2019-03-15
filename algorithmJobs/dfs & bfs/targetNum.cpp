#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

queue<int> getResult(queue<int> preQ, vector<int> numbers) {
    if (numbers.empty()) {
        // 결과 도출 및 반환
        return preQ;
    }

    queue<int> q;

    while (!preQ.empty()) {
        int front = preQ.front();
        preQ.pop();

        q.push(front + numbers[0]);
        q.push(front - numbers[0]);
    }

    numbers.erase(numbers.begin());

    return getResult(q, numbers);
}

int main() {
    vector<int> numbers = {1, 1, 1, 1, 1};
    int target = 3;

    int answer = 0;

    queue<int> q;
    q.push(0);

    queue<int> result = getResult(q, numbers);

    while (!result.empty()) {
        if (result.front() == target) answer++;
        result.pop();
    }

    cout << answer;
}