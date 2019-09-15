#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;

        int isNegative = x == 0 ? 0 : x / abs(x);
        x *= isNegative;

        int result = 0;

        while (true) {
            int part = x % 10;

            if (result > INT_MAX - part) return 0;
            else result += part;

            x /= 10;
            if (x < 1) break;
            else {
                if (result > INT_MAX / 10) return 0;
                else result *= 10;
            }
        }

        result *= isNegative;
        return result;
    }
};

int main() {
    Solution solution;

    cout << solution.reverse(INT_MAX);
}
// https://leetcode.com/problems/reverse-integer/discuss/4544/Understandable-c%2B%2B-solution-handles-overflow