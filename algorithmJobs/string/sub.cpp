#include <iostream>
#include <string>
#include <map>

using namespace std;

int getSmallerNum(string a, string b){
    for(int i=0; i<a.size(); i++){
        // 가장 높은 자리수부터 돌면서 큰 수를 찾음
        if(a[i] < b[i]) return 0;
        else if(a[i] > b[i]) return 1;
    }
    return 1;
}

int main(){

    int shorter;

    string arr[2];
    cin >> arr[0] >> arr[1];

    if(arr[0] == arr[1]) cout << 0;

    if(arr[0].size() < arr[1].size()) shorter = 0;
    else if(arr[0].size() == arr[1].size()) shorter = getSmallerNum(arr[0], arr[1]);
    else shorter = 1;

    arr[1-shorter] = "0"+arr[1-shorter];
    int orgLength = arr[shorter].size();
    for(int i=0; i< arr[1-shorter].size()-orgLength; i++){
        arr[shorter] = "0"+arr[shorter];
    }
    // 쉬운 계산을 위한 전처리 과정

    for(int i=arr[1-shorter].size()-1; i>=0; i--){
        int sub = (arr[1-shorter][i]-'0') - (arr[shorter][i]-'0');
        if(sub < 0){
            arr[1-shorter][i-1] = (arr[1-shorter][i-1]-'1')+'0';
            sub = 10 + sub;
        }
        arr[1-shorter][i] = sub+'0';
    }

    if(shorter == 0) cout << "-";
    int check = 0;
    for(int i=0; i<arr[1-shorter].size(); i++)
        if(arr[1-shorter][i] != (char)'0' || check == 1){
            check = 1;
            cout << arr[1-shorter][i];
        }

}