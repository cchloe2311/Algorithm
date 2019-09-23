#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index = 0;
        int max = 0;

        map<char, int> map;

        bool isDone = false;

        while ((!isDone) && (index != s.length())) {
            for (int i = index; i < s.length(); i++) {
                if (i == s.length() - 1) isDone = true;

                auto iter = map.find(s[i]);
                if (iter == map.end()) {
                    map.insert({s[i], i});
                }
                else {
                    int length = i - index;
                    max = (length > max) ? length : max;

                    index = (*iter).second + 1;
                    map.clear();
                    break;
                }
            }

            max = map.size() > max ? map.size() : max;
        }

        return max;
    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("nfpdmpi");
}

//int index = 0;
//int max = 0;
//
//int check[26];
//memset(check, -1, sizeof(check));
//
//bool isDone = false;
//
//while ((!isDone) && (index != s.length())) {
//for (int i = index; i < s.length(); i++) {
//if (i == s.length() - 1) isDone = true;
//
//if (s[i] < 'a' || s[i] > 'z') {
//} else if (check[s[i] - 'a'] == -1) {
//check[s[i] - 'a'] = i;
//
//if (i == s.length() - 1) isDone = true;
//} else {
//int length = i - index;
//max = (length > max) ? length : max;
//
//index = check[s[i] - 'a'] + 1;
//memset(check, -1, sizeof(check));
//
//break;
//}
//}
//}
//
//return max;