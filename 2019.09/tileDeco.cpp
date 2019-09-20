#include <string>
#include <vector>

#define MAX 81
using namespace std;

long long solution(int N) {
    long long d[MAX] = {0};
    long long area[MAX] = {0};

    d[0] = 0;
    d[1] = 1;
    area[1] = 4;

    for (int i = 2; i <= N; i++) {
        d[i] = d[i - 1] + d[i - 2];
        area[i] = area[i - 1] + 2 * d[i];
    }

    return area[N];
}