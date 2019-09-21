#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index = 0;
        int max = 0;

        int check[26];
        memset(check, -1, sizeof(check));

        bool isDone = false;

        while (!isDone) {
            for (int i = index; i < s.length(); i++) {
                if (check[s[i] - 'a'] == -1) {
                    check[s[i] - 'a'] = i;

                    if (i == s.length() - 1) isDone = true;
                }
                else {
                    int length = i - index;
                    max = (length > max) ? length : max;

                    index = check[s[i] - 'a'] + 1;
                    memset(check, -1, sizeof(check));

                    break;
                }
            }
        }

        return max;
    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("pwwkew");
}