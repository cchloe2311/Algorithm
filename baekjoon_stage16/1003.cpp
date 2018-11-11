#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int numOfTestCase;
    cin >> numOfTestCase;

    int *test = new int[numOfTestCase];
    int maxIndex = 0;
    for(int i=0; i< numOfTestCase; i++) {
        cin >> test[i];
        if(test[i] > test[maxIndex]) maxIndex = i;
    }

    pair<int, int> *d = new pair<int, int>[test[maxIndex]+1];
    d[0] = make_pair(1, 0);
    d[1] = make_pair(0, 1);

    for(int i=2; i<= test[maxIndex]; i++)
        d[i] = make_pair(d[i-2].first + d[i-1].first, d[i-2].second + d[i-1].second);

    for(int i=0; i<numOfTestCase; i++)
        cout << d[test[i]].first <<  " " << d[test[i]].second << endl;
}