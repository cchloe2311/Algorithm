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

    int **costTable = new int*[numOfTestCase];
    long **d = new long*[numOfTestCase];
    for(int i=0; i<numOfTestCase; i++) {
        costTable[i] = new int[3]; // costTable[3][numOfTable]
        d[i] = new long[3];
    }

    for(int i=0; i<numOfTestCase; i++)
        for(int j=0; j<3; j++) cin >> costTable[i][j];

    d[0][0] = costTable[0][0];
    d[0][1] = costTable[0][1];
    d[0][2] = costTable[0][2];

    for(int i=1; i<numOfTestCase; i++)
        for(int j=0; j<3; j++)
            d[i][j] = min(d[i-1][m.find(j)->second.first]+costTable[i][j],
                          d[i-1][m.find(j)->second.second]+costTable[i][j]);

    long minValue = 1000001;
    for(int i=0; i<3; i++)
        if(minValue > d[numOfTestCase-1][i]) minValue = d[numOfTestCase-1][i];

    cout << minValue;
}