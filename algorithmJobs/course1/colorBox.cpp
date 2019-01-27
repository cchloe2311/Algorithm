#include <iostream>
#include <string.h>
#include <map>
#include <vector>
using namespace std;

#define FACE 6

int countKindOfColor(vector<int> extra, int n){
    int *colors = new int[n+1];
    memset(colors, 0, sizeof(int)*(n+1));

    for(int i=0; i<extra.size(); i++) colors[extra[i]]++;

    int numOfColor = 0;
    for(int i=1; i<=n; i++)
        if(colors[i] != 0) numOfColor++;
    return numOfColor;
}

int main(){
    int box[FACE] = {0};
    vector<int> extra;
    int n;
    cin >> n;

    map<int, int> opposite;
    opposite.insert({0, 5});
    opposite.insert({1, 3});
    opposite.insert({2, 4});

    for(int i=0; i<n; i++){
        int color;
        cin >> color;

        for(int i=0; i<3; i++){
            if(box[i] == 0){
                box[i] = color;
                break;
            }
            else if(box[i] == color){
                box[opposite[i]] = color;
                break;
            }
            else if(i == 2) extra.push_back(color);
        }
    }

    int colored = 0;
    for(int i=0; i<FACE; i++){
        if(box[i] != 0) colored++;
    }

    if(colored == FACE) cout << "YES";
    else{
        int numOfExtra = countKindOfColor(extra, n);

        if(FACE - colored <= numOfExtra) cout << "YES";
        else cout << "NO";
    }
}