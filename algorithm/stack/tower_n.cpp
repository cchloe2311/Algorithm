#include <iostream>
#include <utility>
#include <stack>
using namespace std;

int findReceiver(stack<pair<int, int>> &s, int value, int position){
    while(!s.empty() && s.top().first < value){
        s.pop();
    }

    int returnValue;
    if(s.empty()) returnValue = 0;
    else returnValue = s.top().second;

    s.push({value, position});

    return returnValue;
}

int main(){
    int n;
    cin >> n;

    int *towers = new int[n];
    for(int i=0; i<n; i++) cin >> towers[i];

    stack<pair<int, int>> s; // first == value, second == position

    for(int i=0; i<n; i++) cout << findReceiver(s, towers[i], i+1) << " ";
}
