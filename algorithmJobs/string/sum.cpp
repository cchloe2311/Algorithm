#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    map<int, int> m;
    m.insert({0, 1});
    m.insert({1, 0});

    int shorter;

    string arr[2];
    cin >> arr[0] >> arr[1];

    if(arr[0].size() < arr[1].size()) shorter = 0;
    else shorter = 1;

    arr[m[shorter]] = "0"+arr[m[shorter]];
    int orgLength = arr[shorter].size();
    for(int i=0; i< arr[m[shorter]].size()-orgLength; i++){
        arr[shorter] = "0"+arr[shorter];
    }

    for(int i=arr[0].size()-1; i>=0; i--){
        string sum = to_string(arr[0][i]-'0' + arr[1][i]-'0');

        if(sum.size() == 2){
            arr[0][i] = sum[1];
            int temp = arr[0][i-1]-'0' + 1;
            arr[0][i-1] = temp+'0';
        }
        else
            arr[0][i] = sum[0];
    }

    if(arr[0][0] == '0') arr[0] = arr[0].substr(1);
    cout << arr[0];
}