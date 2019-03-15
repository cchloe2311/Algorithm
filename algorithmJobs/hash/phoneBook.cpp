#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = (i + 1); j < phone_book.size(); j++) {
            int length = min(phone_book[i].size(), phone_book[j].size());

            if (phone_book[i].substr(0, length) == phone_book[j].substr(0, length)) {
                answer = false;
                return answer;
            }
        }
    }

    return answer;
}