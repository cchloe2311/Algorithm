#include <iostream>
#include <queue>
#include <math.h>
#include <limits.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        queue<int> q;
        int power = 0;

        while(true) {
            q.push((x % (int)pow(10, power + 1)) / pow(10, power));

            if (abs(x / pow(10, power + 1)) >= 1) power++;
            else break;
        }

        int result = 0;

        while (power >= 0) {
            int part = (q.front() * pow(10, power));
            if (((result > 0) && (result + part > INT_MAX))
            || ((result < 0) && (result + part < INT_MIN))) return 0;
            else result += part;

            q.pop();
            power--;
        }

        return result;
        // (result < INT_MIN || result > INT_MAX) ? 0 : result;
    }
};

int main() {
    Solution solution;

    cout << solution.reverse(1534236469);
}