//#include <iostream>
//#include <utility>
//#include <algorithm>
//using namespace std;
//
//int main(){
//    pair<int, int> fractionA;
//    pair<int, int> fractionB;
//
//    pair<int, int> result;
//
//    cin >> fractionA.first >> fractionA.second;
//    cin >> fractionB.first >> fractionB.second;
//
//    result.first = fractionA.first*fractionB.second + fractionB.first*fractionA.second;
//    result.second = fractionA.second*fractionB.second;
//
//    int m = min(result.first, result.second), gcd = 1;
//
//    for(int i=2; i<=m; i++)
//        if((result.first%i == 0) && (result.second%i == 0)) gcd = i; // 최대 공약수
//
//    result.first /= gcd;
//    result.second /= gcd;
//
//    cout << result.first << " " << result.second;
//}