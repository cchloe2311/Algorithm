#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int findFirst(vector<pair<int, int>> v, int n){
    for(int i=0; i<v.size(); i++)
        if(v[i].first == n) return i;

    return -1;
}

int count(vector<pair<int, int>> v){
    int sum = 0;

    for(int i=0; i<v.size(); i++){
        if(v[i].second <= 2) sum += v[i].second;
        else sum += 2;
    }

    return sum;
}

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    int input, index;

    for(int i=0; i<n; i++) {
        cin >> input;
        index = findFirst(v, input);
        if (index == -1)
            v.push_back({input, 1});
        else v[index].second++;
    }

    if(count(v) >= 6) cout << "YES";
    else cout << "NO";
}