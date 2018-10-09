//
// Created by 최서정 on 2018. 10. 4..
//

#include <iostream>
#include <utility>
using namespace std;

pair<int, int> getDivisor(int r, int b){
    int last = b/2;
    for(int w=1; w<=last; w++)
        if(b%w == 0){
            int l = b/w + 2;
            if(r == (l*2 + 2*w)){
                return make_pair(l, w+2);
            }
        }
}

int main(){
    int r, b;
    cin >> r >> b;
    pair<int, int> result = getDivisor(r, b);
    cout << result.first << " " << result.second;
}