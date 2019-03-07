//#include <iostream>
//#include <vector>
//using namespace std;
//
////bool isPrimeNum(int n){
////    for(int i = 2; i<=n/2; i++)
////        if(n%i == 0) return false;
////    return true;
////}
//
//int getNumOfPrime(int n){
//    int result = 0, check= 1;
//    for(int i=n+1; i<=2*n; i++){
//        check =1;
//        for(int j=2; j<=i/2; j++){
//            if(i%j == 0){
//                check =0;
//                break;
//            }
//        }
//        if(check == 1) result++;
//    }
//    return result;
//}
//
//int main(){
//    int input;
//    vector<int> numOfPrime;
//    cin >> input;
//    while(input != 0){
//        numOfPrime.push_back(getNumOfPrime(input));
//        cin >> input;
//    }
//
//    for(int i=0; i<numOfPrime.size(); i++) cout << numOfPrime[i] << endl;
//}