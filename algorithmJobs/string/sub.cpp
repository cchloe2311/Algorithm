#include <iostream>
#include <string>
#include <map>

using namespace std;

int getSmallerNum(string arr[2]){
    for(int i=arr[0].size(); i>=0; i++){
        // 가장 높은 자리수부터 돌면서 큰 수를 찾음
        if(arr[0][i] < arr[1][i]) return 1;
        else if(arr[0][i] > arr[1][i]) return 0;
    }
    return 0;
}

int main(){

    int shorter;

    string arr[2];
    cin >> arr[0] >> arr[1];

    if(arr[0].size() < arr[1].size()) shorter = 0;
    else if(arr[0].size() == arr[1].size()) shorter = getSmallerNum(arr);
    else shorter = 1;

    //arr[1-shorter] = "0"+arr[1-shorter];
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

    // arr[0] < arr[1] 인 경우, -1 곱해주기
    if(shorter == 0) cout << "-";
    for(int i=0; i<arr[1-shorter].size(); i++) cout << arr[1-shorter][i];
}