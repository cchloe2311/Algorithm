#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct Point{
    int x;
    int y;
    Point(int y, int x) : x(x), y(y){}
};

bool isPossibleToMove(int **map, Point p, int cols){

    if(p.x+1 < cols && map[p.y][p.x+1] == 1) return true;
    else return false;
}

int main(){
    int n;
    cin >> n;

    int *height = new int[n];
    int max = 0;

    for(int i=0; i<n; i++) cin >> height[i];

    int maxHeight = *max_element(height, height+n);
    int **map = new int*[maxHeight];
    for(int i=0; i<maxHeight; i++){
        map[i] = new int[n];
        memset(map[i], 0, sizeof(int)*n); // 일단 모두 0으로 초기화
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<height[i]; j++) map[j][i] = 1;

    for(int i=0; i<n; i++){
        for(int h=0; h<height[i]; h++){
            Point p(h, i);
            while(1){
                if(isPossibleToMove(map, p, n)) p.x++;
                else{
                    if(max < (h+1)*(p.x-i+1)) max = (h+1)*(p.x-i+1);
                    break;
                }
            }
        }
    }

    cout << max;
}