#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

#define NUM -1

static string opener = "(";
static string closer = ")";

int getPriority(string part) {
    pair<string, int> operatorArr[5] = {{"+", 2}, {"-", 2}, {"/", 1}, {"*", 1}, {"(", 3}};

    for (int i = 0; i < 5; i++) {
        if (operatorArr[i].first == part) return operatorArr[i].second;
    }

    return -1;
}

void getPostfix(vector<string> &postfix, stack<string> &s) {
    while ((!s.empty()) && (s.top() != opener)) {
        string top = s.top();

        if(s.top() != opener) postfix.push_back(top);
        s.pop();
    }

    if (!s.empty()) s.pop();
}

vector<string> convertToPostfix(string input) {
    stack<string> s;
//    string postfix = "";
    vector<string> postfix;

    for (int i = 0; i < input.size(); i++) {
        string part = input.substr(i, 1);

        while ((i != (input.size() -1)) && (getPriority(part) == -1) && (getPriority(input.substr(i + 1, 1)) == -1)) {
            part += input[++i];
        }

        if (part == closer) {
             getPostfix(postfix, s);
        }
        else if (part == opener) {
            s.push(part);
        }
        else {
            int priority = getPriority(part);

            if (priority == NUM) {
                postfix.push_back(part);
            }
            else if ((!s.empty()) && (priority >= getPriority(s.top()))) {
                while ((!s.empty()) && (priority >= getPriority(s.top()))) {
                    postfix.push_back(s.top());
                    s.pop();
                }

                s.push(part);
            }
            else {
                s.push(part);
            }
        }
    }

    getPostfix(postfix, s);
    return postfix;
}

int calculatePostfix(vector<string> postfix) {
    string operatorArr[4] = {"+", "-", "/", "*"};

    for (int i = 0; i < postfix.size(); i++) {
        string *p = find(operatorArr, operatorArr+4, postfix[i]);
        if(p != (operatorArr + 4)) {
            int result = 0;

            if(*p == "+") {
                result = atoi(postfix[i - 2].c_str()) + atoi(postfix[i - 1].c_str());
            }
            else if(*p == "-") {
                result = atoi(postfix[i - 2].c_str()) - atoi(postfix[i - 1].c_str());
            }
            else if(*p == "*") {
                result = atoi(postfix[i - 2].c_str()) * atoi(postfix[i - 1].c_str());
            }
            else {
                result = atoi(postfix[i - 2].c_str()) / atoi(postfix[i - 1].c_str());
            }

            postfix[i - 1] = to_string(result);
            postfix.erase(postfix.begin() + (i - 2));
            postfix.erase(postfix.begin() + (i - 1));

            return calculatePostfix(postfix);
        }
    }

    return atoi(postfix[0].c_str());
}

int main() {
    string input;
    cin >> input;

    vector<string> postfix = convertToPostfix(input);

    cout << calculatePostfix(postfix);
}