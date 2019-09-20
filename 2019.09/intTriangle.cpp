#include <string>
#include <vector>
#include <iostream>

#define MAX 125251

using namespace std;

class Node {
    public:
    vector<int> parentNode;
    int value;
    Node(int value) {this->value = value;}
    Node() {}
};

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    Node tree[MAX];
    int index = 0;
    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            tree[index++] = Node(triangle[i][j]);
        }
    }

    int count = 0;
    int stair = 1;
    for (int i = 0; i < index; i++) {
        count++;
        int max = 0;
        for (int j = 0; j < tree[i].parentNode.size(); j++) {
            if (max < tree[tree[i].parentNode[j]].value) max = tree[tree[i].parentNode[j]].value;
        }
        tree[i].value += max;
        cout << tree[i].value << " ";
        if (answer < tree[i].value) answer = tree[i].value;

        if (i + stair <= index) tree[i + stair].parentNode.push_back(i);
        if (i + stair + 1 <= index) tree[i + stair + 1].parentNode.push_back(i);

        if (count == stair) {
            stair++;
            count = 0;
            cout << endl;
        }
    }

    return answer;
}

int main() {
    cout << solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}});
}