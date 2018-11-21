//#include <iostream>
//using namespace std;
//
//int main(){
//    int n, ans=0;
//    cin >> n;
//
//    for(int i=0; i<n; i++){
//        int temp, check=1;
//        cin >> temp;
//
//        if(temp == 1) continue;
//
//        for(int i=2; i<=temp/2; i++){
//            if(temp%i==0){
//                check = 0;
//                break;
//            }
//        }
//        if(check == 1) ans++;
//    }
//
//    cout << ans;
//}