#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define LIMIT 1000001

bool isCameleon(string input, int index, vector<int> v) {
    string pre = input.substr(index);
    int length = input.size() - index;

    if (pre != input.substr(0, length)) {
        return false;
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == index) break;
        if (input.substr(v[i], length) == pre) return true;
    }

    return false;
}

int main() {
    char inputArr[LIMIT];
    scanf("%s", inputArr);

    string input(inputArr);

    vector<int> matchIndex;

    for (int i = 1; i < input.size(); i++) {
        if (input[i] == input[0]) matchIndex.push_back(i);
    }

    for (int i = 0; i < matchIndex.size(); i++) {
        if (isCameleon(input, matchIndex[i], matchIndex)) {
            printf("%s", input.substr(matchIndex[i]).c_str());
//            cout << input.substr(matchIndex[i]);
            return 0;
        }
    }

    printf("-1");
}