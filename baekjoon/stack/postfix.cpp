#include <iostream>
#include <string>
#include <stack>
#include <utility>
using namespace std;

#define NUM -1

static string opener = "(";
static string closer = ")";

int getPriority(string str) {
    pair<string, int> operatorArr[5] = {{"+", 2}, {"-", 2}, {"/", 1}, {"*", 1}, {"(", 3}};

    for (int i = 0; i < 5; i++) {
        if (operatorArr[i].first == str) return operatorArr[i].second;
    }

    return -1;
}

string getPostfix(string postfix, stack<string> &s) {
    while ((!s.empty()) && (s.top() != opener)) {
        string top = s.top();

        if(s.top() != opener) postfix += top;
        s.pop();
    }

    if (!s.empty()) s.pop();

    return postfix;
}

int main() {
    string input;
    cin >> input;

    stack<string> s;
    string postfix = "";

    for (int i = 0; i < input.size(); i++) {
        string part = input.substr(i, 1);
        if (part == closer) {
            postfix = getPostfix(postfix, s);
        }
        else if (part == opener) {
            s.push(part);
        }
        else {
            int priority = getPriority(part);

            if (priority == NUM) {
                postfix += part;
            }
            else if ((!s.empty()) && (priority >= getPriority(s.top()))) {
                while ((!s.empty()) && (priority >= getPriority(s.top()))) {
                    postfix += s.top();
                    s.pop();
                }

                s.push(part);
            }
            else {
                s.push(part);
            }
        }
    }

    postfix = getPostfix(postfix, s);

    cout << postfix;

}