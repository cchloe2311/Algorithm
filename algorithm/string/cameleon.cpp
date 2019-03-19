#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isCameleon(string input, int index) {
    string pre = input.substr(index);
    int length = input.size() - index;

    if (pre != input.substr(0, length)) {
        return false;
    }

    for (int i = 1; i < index; i++) {
        if (input.substr(i, length) == pre) return true;
    }

    return false;
}

int main() {
    string input;
    cin >> input;

    vector<int> matchIndex;

    for (int i = 1; i < input.size(); i++) {
        if (input[i] == input[0]) matchIndex.push_back(i);
    }

    for (int i = 0; i < matchIndex.size(); i++) {
        if (isCameleon(input, matchIndex[i])) {
            cout << input.substr(matchIndex[i]);
            return 0;
        }
    }

    cout << -1;
}