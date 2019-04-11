#include <iostream>
#include <vector>
using namespace std;

int n, m;
int startY, startX;

int map[500][500];

int iType[4][4] = {
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
};

int oType[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0}
};

int lType1[4][4] = {
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 0, 0}
};

int lType2[4][4] = {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
};

int sType1[4][4] = {
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0}
};

int sType2[4][4] = {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0}
};

int tType[4][4] = {
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0}
};

class Shape {
public:
    int shape[4][4];

    Shape(int shape[4][4]) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) this->shape[i][j] = shape[i][j];
        }
    }
};

vector<Shape> shapes;

void initVars() {
    shapes.push_back(Shape(iType));
    shapes.push_back(Shape(oType));
    shapes.push_back(Shape(tType));
    shapes.push_back(Shape(lType1));
    shapes.push_back(Shape(lType2));
    shapes.push_back(Shape(sType1));
    shapes.push_back(Shape(sType2));

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> map[i][j];
    }
}

void printShape(int shape[4][4]) {
    for (int i = startY; i < 4; i++) {
        for (int j = startX; j < 4; j++) cout << shape[i][j] << " ";
        cout << endl;
    }
}

void rotateShape(int shape[4][4]) {
    int temp[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >=0; j--) {
            temp[i][3 - j] = shape[j][i];
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) shape[i][j] = temp[i][j];
    }
}

void setStartIndex(int shape[4][4]) {
    startY = -1;
    startX = -1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (shape[i][j] == 1) {
                startY = i;
                break;
            }
        }

        if (startY != -1) break;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (shape[j][i] == 1) {
                startX = i;
                break;
            }
        }

        if (startX != -1) break;
    }
}

bool isInRange(int y, int x) {
    if ((y >= 0) && (y < n) && (x >= 0) && (x < m)) return true;
    else return false;
}

int getMaxArea(int shape[4][4]) {
    int max = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;

            int tempY = i;
            int tempX = j;

            bool isInMap = true;

            for (int shapeI = startY; shapeI < 4; shapeI++) {
                for(int shapeJ = startX; shapeJ < 4; shapeJ++) {
                    if (isInRange(tempY, tempX)) {
                        if (shape[shapeI][shapeJ] == 1) {
                            sum += map[tempY][tempX];
                        }
                    }
                    else {
                        if (shape[shapeI][shapeJ] == 1) {
                            isInMap = false;
                            sum = 0;

                            break;
                        }
                    }

                    tempX++;
                }
                if (!isInMap) break;
                tempX = j;
                tempY++;
            }

            if (sum > max) max = sum;
        }
    }

    return max;
}

int main() {
    initVars();

    int max = -1;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            startY = 0;
            startX = 0;

            rotateShape(shapes[i].shape);
            setStartIndex(shapes[i].shape);

            int area = getMaxArea(shapes[i].shape);
            if (area > max) max = area;
        }
    }

    cout << max;
}