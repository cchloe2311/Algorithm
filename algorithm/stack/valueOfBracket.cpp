#include <iostream>
#include <stack>

#define ROUND 1
#define SQUARE -1

using namespace std;

int solution(string input) {
    stack<int> s;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') s.push(ROUND);
        else if (input[i] == '[') s.push(SQUARE);
        else {
            int value = 0;
            while((!s.empty()) && (s.top() != ROUND) && (s.top() != SQUARE)) {
                value += s.top();
                s.pop();
            }
            value = value > 0 ? value : 1;

            if (s.empty()) return 0;
            if (input[i] == ')' && s.top() != ROUND) return 0;
            if (input[i] == ']' && s.top() != SQUARE) return 0;

            if (input[i] == ')') value *= 2;
            else if (input[i] == ']') value *= 3;

            s.pop();
            s.push(value);
        }
    }

    int res = 0;
    while(!s.empty()) {
        if ((s.top() == ROUND) || (s.top() == SQUARE)) return 0;
        res += s.top();
        s.pop();
    }

    return res;
}

int main() {
    string input;
    cin >> input;

    cout << solution(input);
}