#include <iostream>
#include <utility>
#include <stack>

using namespace std;

struct Rect{
    int pre;
    int suf;
    int height;
    Rect():height(0), pre(0), suf(0) {};
    int getArea(){
        int width = suf - pre -1;

        return width*height;
    }
};

int findShoter(stack<pair<int, int>> &s, int value, int position, int defaultValue){
    while(!s.empty() && s.top().first >= value){
        s.pop();
    }

    int returnValue;
    if(s.empty()) returnValue = defaultValue;
    else returnValue = s.top().second;

    s.push({value, position});

    return returnValue;
}

int main(){
    int n;
    cin >> n;

    Rect *rects = new Rect[n];
    int max = 0;

    for(int i=0; i<n; i++) cin >> rects[i].height;

    stack<pair<int, int>> s;
    for(int i=0; i<n; i++) rects[i].pre = findShoter(s, rects[i].height, i+1, 0);

    while(!s.empty()) s.pop();
    for(int i=n-1; i>=0; i--) rects[i].suf = findShoter(s, rects[i].height, i+1, n+1);

    for(int i=0; i<n; i++){
        int area = rects[i].getArea();
        if(max < area) max = area;
    }

    cout << max;
}