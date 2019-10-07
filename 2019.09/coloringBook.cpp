// https://programmers.co.kr/learn/courses/30/lessons/1829
#include <vector>
#include <iostream>

using namespace std;

int dy[4];
int dx[4];

int size_of_one_area;

bool isInRange(int m, int n, int y, int x) {
    if ((y >= 0) && (y < m) && (x >= 0) && (x < n)) return true;
    else return false;
}

void getOneArea(int m, int n, int y, int x, vector<vector<int>> &picture) {
    int color = picture[y][x];
    size_of_one_area++;
    picture[y][x] = 0;

    for (int i = 0; i < 4; i++) {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (!isInRange(m, n, nextY, nextX)) continue;
        if (picture[nextY][nextX] == color) getOneArea(m, n, nextY, nextX, picture);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    dy[0] = 0, dy[1] = 0, dy[2] = -1, dy[3] = +1;
    dx[0] = -1, dx[1] = +1, dx[2] = 0, dx[3] = 0;

    int number_of_area = 0; // 그림에 몇 개의 영역이 있는지와
    int max_size_of_one_area = 0; // 가장 큰 영역의 넓이는 얼마인지 계산하는 프로그램을 작성하

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (picture[y][x] == 0) continue;

            number_of_area++;
            size_of_one_area = 0;

            getOneArea(m, n, y, x, picture);
            if (size_of_one_area > max_size_of_one_area) max_size_of_one_area = size_of_one_area;
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    vector<int> answer = solution(6, 4, {{1, 1, 1, 0},
                                         {1, 2, 2, 0},
                                         {1, 0, 0, 1},
                                         {0, 0, 0, 1},
                                         {0, 0, 0, 3},
                                         {0, 0, 0, 3}});
    cout << answer[0] << " " << answer[1];
}