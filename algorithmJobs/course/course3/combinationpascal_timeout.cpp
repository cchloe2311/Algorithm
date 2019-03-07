//#include <iostream>
//using namespace std;
//
//long long getCombination(int n, int r){
//    if(n == r) return 1;
//    else if(r == 0) return 1;
//    else return getCombination(n-1, r) + getCombination(n-1, r-1);
//}
//
//int main(){
//    int n, r;
//    cin >> n >> r;
//
//    cout << getCombination(n, r);
//}
//
//// 마지막 테스트케이스에서 타임아웃
//// nCr = n - 1Cr + n - 1Cr - 1 점화식 사용