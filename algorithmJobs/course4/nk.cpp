#include <iostream>
#include <vector>

using namespace std;

void printResult(vector<string> v){
    for(int i=0; i<v.size(); i++)
        cout << v[i]<< endl;
}

void getNdigitKnum(vector<string> v, int n, int k){
    vector<string> result;
    for(int i=0; i<k; i++)
        for(int j=0; j<v.size(); j++)
            result.push_back(char(48+i)+v[j]);
    if(n > 1) getNdigitKnum(result, --n, k);
    else printResult(result);
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<string> init;
    init.push_back("");
    getNdigitKnum(init, n, k);

}