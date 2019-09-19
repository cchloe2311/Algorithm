#include <iostream>
using namespace std;

int n;

void initVar() {
    n = 0;
    cin >> n;
}

int getNum() {
    int num = 0;

    if (n >= 10) num += 9;
    else return n;

    if (n >= 100) num +=90;
    else return n;

    // 세자리수
    for (int i = 1; i <= n / 100; i++) {
        int second = 1;
        for (int j = (1 - i); j <= (9 - i)/2; j++) {
            if ((second + j >= 0) && ((i*100 + second*10 + second+j) <= n)) num++;
            second++;
        }
    }

    return num;
}

int main() {
    initVar();
    cout << getNum();
}