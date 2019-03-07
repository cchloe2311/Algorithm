#include <iostream>
#include <vector>
#include <algorithm>
#define DIGITS 2
using namespace std;

void printResult(vector<string> v, int k){
    sort(v.begin(), v.end());

    for(int i=v.size()-1; i>=0; i--){
        int check =0;
        for(int j=0; j<v[i].length(); j++)
            if(v[i][j] == '1') check ++;
        if(check == k) cout << v[i] << endl;
    }
}

bool isOver(string str, int k){
    int check =0;
    for(int i=0; i<str.length(); i++){
        if(str[i] == '1') check++;
        if(check > k) return true;
    }
    return false;
}

void getNdigitKnum(vector<string> v, int n, int k){
    int vSize = v.size();
    for(int i=0; i<DIGITS; i++)
        for(int j=0; j<vSize; j++){
            if(isOver(char(48+i)+v[j], k)) continue;
            v.push_back(char(48+i)+v[j]);
        }
    v.erase(v.begin(), v.begin()+vSize);

    if(n > 1) getNdigitKnum(v, --n, k);
    else printResult(v, k);
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<string> init;
    init.push_back("");
    getNdigitKnum(init, n, k);
}