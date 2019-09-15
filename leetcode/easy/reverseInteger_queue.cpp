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

        if (x == INT_MIN) return 0;

        int isNegative = x == 0 ? 0 : x / abs(x);
        x *= isNegative;

        while(true) {
            q.push((x % (int)pow(10, power + 1)) / pow(10, power));

            if (abs(x / pow(10, power + 1)) >= 1) power++;
            else break;
        }

        int result = 0;

        while (power >= 0) {
            int part = (q.front() * pow(10, power));
            if ((part < 0) || (result > INT_MAX - part)) return 0;
            else result += part;

            q.pop();
            power--;
        }

        result *= isNegative;
        return result;
    }
};

int main() {
    Solution solution;

    cout << solution.reverse(1534236469);
}
// https://leetcode.com/problems/reverse-integer/discuss/4544/Understandable-c%2B%2B-solution-handles-overflow