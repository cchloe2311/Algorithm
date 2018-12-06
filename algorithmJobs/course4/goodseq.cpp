#include <iostream>
#define DIGITS 3
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

bool getNdigitGoodSeq(string str, int n){
    for(int i=0; i<DIGITS; i++){
        if(isGoodSeq(str+char(49+i))){
            if(n != 1) {
                if(getNdigitGoodSeq(str+char(49+i), n-1)) return true;
            }
            else{
                cout << str+char(49+i)<< endl;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;

    if(n == 1){
        cout <<1;
        return 1;
    }


    string init = "";
    bool result = getNdigitGoodSeq(init, n);
}