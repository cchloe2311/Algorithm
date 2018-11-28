//#include <iostream>
//#include <math.h>
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
//    long long combination = getCombination(n, r);
//
//    int digitN = 0;
//    while(1){
//        if(combination / pow(10, digitN) < 1) break;
//        else digitN++;
//    }
//
//    for(int i=0; i<=digitN; i++){
//        if(combination % (int)pow(10, i) != 0){
//            cout << i-1;
//            return 0;
//        }
//    }
//}