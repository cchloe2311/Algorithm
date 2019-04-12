#include <iostream>
#include <vector>
#include <map>
using namespace std;

int tc, n;
vector<string> orders[100];
char cube[6][3][3] = {
        {
            {'w', 'w', 'w'},
            {'w', 'w', 'w'},
            {'w', 'w', 'w'}
        },
        {
            {'g', 'g', 'g'},
            {'g', 'g', 'g'},
            {'g', 'g', 'g'}
        },
        {
            {'r', 'r', 'r'},
            {'r', 'r', 'r'},
            {'r', 'r', 'r'}
        },
        {
            {'b', 'b', 'b'},
            {'b', 'b', 'b'},
            {'b', 'b', 'b'}
        },
        {
            {'o', 'o', 'o'},
            {'o', 'o', 'o'},
            {'o', 'o', 'o'}
        },
        {
            {'y', 'y', 'y'},
            {'y', 'y', 'y'},
            {'y', 'y', 'y'}
        }
    };

class Neighbor {
public:
    int surface;
    vector<int> y;
    vector<int> x;

    Neighbor(int surface, vector<int> y, vector<int> x) {
        this->surface = surface;
        for (int i = 0; i <y.size(); i++) this->y.push_back(y[i]);
        for (int i = 0; i <x.size(); i++) this->x.push_back(x[i]);
    }
};

map<char, int> surfaceM = {{'U', 0}, {'D', 5}, {'F', 2}, {'B', 4}, {'L', 1}, {'R', 3}};
map<int, vector<Neighbor>> rotateM = {
        {0,
                    {
                            Neighbor(1, {0, 0, 0}, {0, 1, 2}),
                            Neighbor(4, {0, 0, 0}, {0, 1, 2}),
                            Neighbor(3, {0, 0, 0}, {0, 1, 2}),
                            Neighbor(2, {0, 0, 0}, {0, 1, 2}),
                    }
        },
        {5,
                    {
                            Neighbor(2, {2, 2, 2}, {0, 1, 2}),
                            Neighbor(3, {2, 2, 2}, {0, 1, 2}),
                            Neighbor(4, {2, 2, 2}, {0, 1, 2}),
                            Neighbor(1, {2, 2, 2}, {0, 1, 2})
                    }
        },
        {1,
                {
                        Neighbor(2, {0, 1, 2}, {0, 0, 0}),
                        Neighbor(5, {0, 1, 2}, {0, 0, 0}),
                        Neighbor(4, {2, 1, 0}, {2, 2, 2}),
                        Neighbor(0, {0, 1, 2}, {0, 0, 0})
                }
        },
        {3,
                {
                        Neighbor(0, {0, 1, 2}, {2, 2, 2}),
                        Neighbor(4, {2, 1, 0}, {0, 0, 0}),
                        Neighbor(5, {0, 1, 2}, {2, 2, 2}),
                        Neighbor(2, {0, 1, 2}, {2, 2, 2}),
                }
        },
        {2,
                {
                        Neighbor(0, {2, 2, 2}, {0, 1, 2}),
                        Neighbor(3, {0, 1, 2}, {0, 0, 0}),
                        Neighbor(5, {0, 0, 0}, {2, 1, 0}),
                        Neighbor(1, {2, 1, 0}, {2, 2, 2}),
                }
        },
        {4,
                {
                        Neighbor(1, {2, 1, 0}, {0, 0, 0}),
                        Neighbor(5, {2, 2, 2}, {2, 1, 0}),
                        Neighbor(3, {0, 1, 2}, {2, 2, 2}),
                        Neighbor(0, {0, 0, 0}, {0, 1, 2})
                }
        }
};

void rotate(int surface, int direction) {
    vector<Neighbor> neighbors(rotateM.find(surface)->second);

    int time;
    if (direction == -1) time = 3;
    else time = 1;

    char tempSurface[3][3];

    for (int i = 0; i < time; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 2; k >= 0; k--) tempSurface[j][2 - k] = cube[surface][k][j];
        }

        for (int k = 0; k < 3; k++) {
            for (int j = 0; j < 3; j++) cube[surface][k][j] = tempSurface[k][j];
        }
    }

    direction *= -1;

    int pre = 0;
    int post = 0;
    post = (post + direction + 4) % 4;

    char temp[3];
    temp[0] = cube[neighbors[pre].surface][neighbors[pre].y[0]][neighbors[pre].x[0]];
    temp[1] = cube[neighbors[pre].surface][neighbors[pre].y[1]][neighbors[pre].x[1]];
    temp[2] = cube[neighbors[pre].surface][neighbors[pre].y[2]][neighbors[pre].x[2]];

    for (int i = 0; i < 3; i++) {
        cube[neighbors[pre].surface][neighbors[pre].y[0]][neighbors[pre].x[0]]
                = cube[neighbors[post].surface][neighbors[post].y[0]][neighbors[post].x[0]];
        cube[neighbors[pre].surface][neighbors[pre].y[1]][neighbors[pre].x[1]]
                = cube[neighbors[post].surface][neighbors[post].y[1]][neighbors[post].x[1]];
        cube[neighbors[pre].surface][neighbors[pre].y[2]][neighbors[pre].x[2]]
                = cube[neighbors[post].surface][neighbors[post].y[2]][neighbors[post].x[2]];

        // pre, post - 1
        pre = (pre + direction + 4) % 4;
        post = (post + direction + 4) % 4;
    }

    cube[neighbors[pre].surface][neighbors[pre].y[0]][neighbors[pre].x[0]] = temp[0];
    cube[neighbors[pre].surface][neighbors[pre].y[1]][neighbors[pre].x[1]] = temp[1];
    cube[neighbors[pre].surface][neighbors[pre].y[2]][neighbors[pre].x[2]] = temp[2];
}

int main() {
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        string input;

        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> input;
            orders[i].push_back(input);
        }
        cin.ignore();
    }

    for (int i = 0; i < tc; i++) {
        for (int j = 0; j <orders[i].size(); j++) {
            int surface = surfaceM.find(orders[i][j][0])->second;
            int direction = (orders[i][j][1] == '+') ? 1 : -1;

            rotate(surface, direction);
        }
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) cout << cube[0][y][x];
            cout << endl;
        }

        for (int j = orders[i].size() - 1; j >= 0; j--) {
            int surface = surfaceM.find(orders[i][j][0])->second;
            int direction = (orders[i][j][1] == '+') ? 1 : -1;

            rotate(surface, direction);
            rotate(surface, direction);
            rotate(surface, direction);
        }
    }
}