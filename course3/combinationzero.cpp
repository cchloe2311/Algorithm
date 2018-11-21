//#include <iostream>
//#include <utility>
//using namespace std;
//
//int main(){
//    int n, m;
//    cin >> n >> m;
//
//    pair<int, int> upper;
//    pair<int, int> lowwer;
//
//    upper = make_pair(0, 0);
//    lowwer = make_pair(0, 0);
//
//    for(int i= n; i>m; i--){
//        int num = i;
//        while(1){
//            if(num % 5 == 0){
//                upper.first++;
//                num /= 5;
//            }
//            else if(num % 2 == 0){
//                upper.second++;
//                num /= 2;
//            }
//            else break;
//        }
//    }
//
//    for(int i=n-m; i>0; i--){
//        int num = i;
//        while(1){
//            if(num % 5 == 0){
//                lowwer.first++;
//                num /= 5;
//            }
//            else if(num % 2 == 0){
//                lowwer.second++;
//                num /= 2;
//            }
//            else break;
//        }
//    }
//
//    int numOf5 = upper.first-lowwer.first;
//    int numOf2 = upper.second-lowwer.second;
//
//    if(numOf5 > numOf2) cout << numOf2;
//    else cout << numOf5;
//}