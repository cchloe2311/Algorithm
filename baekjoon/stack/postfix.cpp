#include <iostream>
#include <string>
#include <stack>
using namespace std;

static string opener = "(";
static string closer = ")";

bool isOperator(string str) {
    string operatorArr[4] = {"+", "-", "/", "*"};

    for (int i = 0; i < 4; i++) {
        if (operatorArr[i] == str) return true;
    }

    return false;
}

void getPostfix(stack<string> &s) {
    string postfix = "";
    while ((!s.empty()) && (s.top() != opener)) {
        string temp = s.top();

        if (isOperator(temp)) postfix.push_back(temp[0]);
        else  postfix = (temp + postfix);

        s.pop();
    }
    if (!s.empty()) s.pop();
    s.push(postfix);
}

int main() {
    string input;
    cin >> input;

    stack<string> s;

    for (int i = 0; i < input.size(); i++) {
        string part = input.substr(i, 1);
        if (part == closer) {
            getPostfix(s);
        }
        else {
            s.push(part);
        }
    }

    getPostfix(s);

    cout << s.top();
}