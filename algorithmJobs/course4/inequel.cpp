#include <iostream>
#include <vector>
using namespace std;

// > : 62 , < : 60

bool isRightMinCase(string str, vector<char> inequal){
    int inequalIndex = inequal.size()-1;
    int cmp1 = (int)str[str.length()-1] - '0';

    for(int i=1; i<str.length(); i++){
        if(str[i] == str[0]) return false;
    }

    for(int i=str.length()-2; i>=0; i--){
        int cmp2 = (int)str[i] - '0';
        if(inequal[inequalIndex--] == '>') {
            if (cmp2 <= cmp1) return false;
        }
        else {
            if (cmp2 >= cmp1) return false;
        }
        cmp1 = cmp2;
    }
    return true;
}

bool isRightMaxCase(string str, vector<char> inequal){
    for(int i=0; i<str.length()-1; i++){
        if(str[i] == str[str.length()-1]) return false;
    }

    int cmp1 = (int)str[0] - '0';
    for(int i=1; i<str.length(); i++){
        int cmp2 = (int)str[i] - '0';
        if(inequal[i-1] == '>') {
            if (cmp2 > cmp1) return false;
        }
        else {
            if (cmp2 < cmp1) return false;
        }
        cmp1 = cmp2;
    }
    return true;
}

void getMinNdigitKnum(vector<string> v, int n, int k, vector<char> inequal){
    vector<string> result;
    for(int i=0; i<k; i++)
        for(int j=0; j<v.size(); j++)
            if(isRightMinCase(char(48+i)+v[j], inequal)){
                if(n != 1) result.push_back(char(48+i)+v[j]);
                else{
                    cout << char(48+i)+v[j] << endl;
                    return;
                }
            }
    if(n > 1) getMinNdigitKnum(result, --n, k, inequal);
}

void getMaxNdigitKnum(vector<string> v, int n, int k, vector<char> inequal){
    vector<string> result;
    for(int j=0; j<v.size(); j++)
        for(int i=k-1; i>=0; i--)
            if(isRightMaxCase(v[j]+char(48+i), inequal)){
                if(n != 1) result.push_back(v[j]+char(48+i));
                else{
                    cout << v[j]+char(48+i) << endl;
                    return;
                }
            }
    if(n > 1) getMaxNdigitKnum(result, --n, k, inequal);
}

int main(){
    int n;
    cin >> n; // n+1자리수의 10진수 케이스를 찾는 것과 같음
    vector<char> inequal;
    inequal.resize(n);
    for(int i=0; i<n; i++) cin >> inequal[i];

    vector<string> init;
    init.push_back("");
    getMaxNdigitKnum(init, n+1, 10, inequal);
    getMinNdigitKnum(init, n+1, 10, inequal);
}