#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int *result = new int[n];
    memset(result, 0, sizeof(int) * n);

    int tempInput;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> tempInput;

            if ((tempInput % 2) == 1) result[i] += tempInput;
        }
    }

    for (int i = 0; i < n; i++) cout << "#" << i + 1 << " " << result[i] << endl;
}