//#include <iostream>
//#include <vector>
//#include <math.h>
//
//using namespace std;
//
//int main(){
//    int n, k;
//    cin >> n >> k;
//    int startRange=0, endRange;
//    for(int i=0; i<k; i++) startRange += pow(2, i);
//    endRange = pow(2, n)-1;
//
//    for(int i= endRange; i>=startRange; i--){
//        int temp = i, check = 0;
//        int *binary = new int[n];
//
//        for(int j=n-1; j>=0; j--){
//            binary[j] = temp%2;
//            if(temp%2 == 1) check ++;
//            temp /= 2;
//        }
//
//        if(check == k) {
//            for (int j = 0; j < n; j++) cout << binary[j];
//            cout << endl;
//        }
//
//        delete[] binary;
//    }
//}