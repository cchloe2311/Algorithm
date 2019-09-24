#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index = 0;
        int max = 0;

        string part = "";

        for (int i = 0; i < s.length(); i++) {
            size_t pos = part.find(s[i]);
            if (pos != string::npos) {
                index += (pos + 1);
            }

            part = s.substr(index, i + 1 - index);
            if (part.length() > max) max = part.length();
        }

        return max;
    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbb");
}