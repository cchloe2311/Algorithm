//#include <iostream>
//#include <vector>
//#include <sstream>
//#include <algorithm>
//#include <map>
//
//#define DIGITS 3
//
//using namespace std;
//
//string intTOStr(int n){
//    stringstream ss;
//    ss << n;
//    return ss.str();
//}
//
//bool isMakeZero(string curCase, int n){
//    string toStr = "";
//    vector<int> opPosition;
//
//    char sum = '+';
//    char sub = '-';
//
//    for(int i=0; i<curCase.length(); i++){
//        toStr += intTOStr(i+1);
//        switch (curCase[i]){
//            case '0' :
//                opPosition.push_back(toStr.length());
//                toStr += sum;
//                break;
//            case '1' :
//                opPosition.push_back(toStr.length());
//                toStr += sub;
//                break;
//            default:
//                break;
//        }
//    }
//    toStr += intTOStr(n);
//    opPosition.push_back(toStr.length());
//
//    int result = atoi(toStr.substr(0, opPosition[0]).c_str());
//
//    for(int i=0; i<opPosition.size()-1; i++){
//        if(toStr[opPosition[i]] == sum)
//            result += atoi(toStr.substr(opPosition[i]+1, opPosition[i+1]-opPosition[i]-1).c_str());
//        else
//            result -= atoi(toStr.substr(opPosition[i]+1, opPosition[i+1]-opPosition[i]-1).c_str());
//    }
//
//    if(result == 0) return true;
//    else return false;
//}
//
//void printResult(vector<string> result, int n){
//    map<char, string> opMap;
//    opMap.insert({'0', " + "});
//    opMap.insert({'1', " - "});
//    opMap.insert({'2', " . "});
//
//    for(int i=0; i<result.size(); i++){
//        for(int j=0; j<n-1; j++) cout << j+1 << opMap[result[i][j]];
//        cout << n << endl;
//        if(i == 19) break;
//    }
//    cout << result.size();
//}
//
//void checkResult(vector<string> v, int n){
//    map<char, string> opMap;
//    opMap.insert({'0', " + "});
//    opMap.insert({'1', " - "});
//    opMap.insert({'2', " . "});
//
//    vector<string> result;
//    for(int i=0; i<DIGITS; i++)
//        for(int j=0; j<v.size(); j++){
//            if(isMakeZero(char(48+i)+v[j], n)){
//                result.push_back(char(48+i)+v[j]);
//            }
//        }
//    printResult(result, n);
//}
//
//void getNdigitKnum(vector<string> v, int n, int orgN){
//    vector<string> result;
//    for(int i=0; i<DIGITS; i++)
//        for(int j=0; j<v.size(); j++)
//            result.push_back(char(48+i)+v[j]);
//    if(n > 2) getNdigitKnum(result, --n, orgN);
//    else checkResult(result, orgN);
//}
//
//int main(){
//    int n;
//    cin >> n;
//
//    // n-1자리의 3진수를 만드는 것과 같음
//
//    if(n == 1){
//        cout << 0;
//        return 1;
//    }
//
//    vector<string> init;
//    init.push_back("");
//
//    getNdigitKnum(init, n-1, n);
//}