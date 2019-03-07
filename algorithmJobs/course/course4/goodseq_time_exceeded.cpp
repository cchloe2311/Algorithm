#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isGoodSeq(string str){
    for(int i=1; i<str.length(); i++){
        string tempPreStr = str.substr(0, i);
        string postStr = str.substr(i);

        for(int j=0; j<tempPreStr.length(); j++){
            string preStr = tempPreStr.substr(j);
            for(int k=0; k<preStr.length(); k++){
                if(preStr[k] != postStr[k]) break;
                if(k == preStr.length()-1) return false;
            }
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    char validElement[2] = {'2', '3'};

    string startCase = "";
    string minCase = "";
    for(int i=0; i<n; i++){
        startCase += "1";
        minCase += "3";
    }

    vector<string> Ncase;
    queue<string> q;
    q.push(startCase);
    Ncase.push_back(startCase);

    while(!q.empty()){
        string frontCase = q.front();
        q.pop();

        for(int i = n-1; i>=0; i--){
            string tempCase = frontCase;
            for(int j=0; j<2; j++){
                tempCase[i] = validElement[j];
                if(find(Ncase.begin(), Ncase.end(), tempCase) != Ncase.end()) continue;
                q.push(tempCase);
                Ncase.push_back(tempCase);

                if((minCase.compare(tempCase) > 0)) // 아예 과정을 효율적으로 하는 방법은 없을까
                    if(isGoodSeq(tempCase)) minCase = tempCase;
            }
        }
    }

    cout << minCase;
}