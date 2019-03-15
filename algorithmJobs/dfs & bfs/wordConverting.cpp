#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;

bool isMatchExceptN(string a, string b, int n) {
    if(a == b) return false;

    if (a.substr(0, n) != b.substr(0, n)) return false;
    else if (a.substr(n + 1) != b.substr(n + 1)) return false;

    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    int length = begin.size();

    int *visited = new int[words.size()];
    memset(visited, 0, sizeof(int) * (words.size()));
    queue<pair<string, int> > q;
    q.push({begin, 0});

    while (!q.empty()) {
        pair<string, int> front = q.front();
        q.pop();

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < words.size(); j++) {
                if ((isMatchExceptN(front.first, words[j], i)) && (visited[j] == 0)) {
                    if (words[j] == target) {
                        answer = front.second + 1;
                        return answer;
                    }

                    q.push({words[j], front.second + 1});
                    visited[j] = 1;
                }
            }
        }
    }

    return answer;
}

int main() {
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << solution("hit", "cog", words);
}