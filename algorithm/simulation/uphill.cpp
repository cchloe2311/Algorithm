#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int n, l;
int map[100][100];

bool isPossiblePath(stack<int> pre) {
    stack<pair<int, bool>> post;

    while(!pre.empty()) {
        int preTop = pre.top();
        pre.pop();

        if (post.empty()) post.push({preTop, true});
        else {
            pair<int, bool> postTop = post.top();

            if (preTop == postTop.first) {
                post.push({preTop, true});
            }
            else if (preTop - postTop.first == 1) {
                for (int i = 0; i < l; i++) {
                    if (post.empty()) return false;
                    else if (post.top().first != postTop.first) return false;
                    else if (!post.top().second) return false;
                    else post.pop();
                }

                post.push({preTop, true});
            }
            else if (preTop - postTop.first == -1){
                for (int i = 1; i < l; i++) {
                    if (pre.empty()) return false;
                    else if (pre.top() != preTop) return false;
                    else pre.pop();
                }

                post.push({preTop, false});
            }
            else return false;
        }
    }

    return true;
}

int main() {
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> map[i][j];
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        stack<int> pre;
        for (int j = 0; j < n; j++) pre.push(map[i][j]);

        if (isPossiblePath(pre)) count++;
    }

    for (int j = 0; j < n; j++) {
        stack<int> pre;
        for (int i = 0; i < n; i++) pre.push(map[i][j]);

        if (isPossiblePath(pre)) count++;
    }

    cout << count;
}