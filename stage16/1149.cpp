//
// Created by 최서정 on 2018. 7. 25..
//

#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    int numOfTestCase;
    cin >> numOfTestCase;

    map<int, pair<int, int>> m;
    m.insert(make_pair(0, make_pair(1, 2)));
    m.insert(make_pair(1, make_pair(0, 2)));
    m.insert(make_pair(2, make_pair(0, 1)));

    int **costTable = new int*[3];
    int **d = new int*[3];
    for(int i=0; i<3; i++) {
        costTable[i] = new int[numOfTestCase]; // costTable[3][numOfTable]
        d[i] = new int[numOfTestCase];
    }

    for(int i=0; i<numOfTestCase; i++)
        cin >> costTable[0][i] >> costTable[1][i] >> costTable[2][i];
// 좌표가 잘못됐음

    d[0][0] = costTable[0][0];
    d[1][0] = costTable[1][0];
    d[2][0] = costTable[2][0];

    for(int i=1; i<numOfTestCase; i++)
        for(int j=0; j<3; j++)
            d[j][i] = min(d[m.find(j)->second.first][i-1]+costTable[j][i],
                          d[m.find(j)->second.second][i-1]+costTable[j][i]);

    int minValue = INT_MAX;
    for(int i=0; i<3; i++)
        if(minValue > d[i][numOfTestCase-1]) minValue = d[i][numOfTestCase-1];

    cout << minValue;
}