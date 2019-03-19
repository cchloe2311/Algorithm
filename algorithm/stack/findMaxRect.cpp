#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct Point{
    int x;
    int y;
    Point(int y, int x) : x(x), y(y){}
};

bool isPossibleToMove(Point p, int nextCol, int cols){

    if((nextCol-1) < p.y) return false;
    else return true;
}

int main(){
    int n;
    cin >> n;

    int *height = new int[n+1];
    int max = 0;

    for(int i=0; i<n; i++) cin >> height[i];
    height[n] = -1;

    int maxHeight = *max_element(height, height+n);

    for(int i=0; i<n; i++){
        for(int h=0; h<height[i]; h++){
            Point p(h, i);
            while(1){
                if(isPossibleToMove(p, height[p.x+1], n)) p.x++;
                else{
                    if(max < (h+1)*(p.x-i+1)) max = (h+1)*(p.x-i+1);
                    break;
                }
            }
        }
    }

    cout << max;
}