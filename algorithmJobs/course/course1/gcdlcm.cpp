//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main(){
//    int n,m;
//    int s, max = 1;
//    cin >> n >> m;
//    if(n == 0 || m == 0){
//        cout << 0 << endl << 0;
//        exit(1);
//    }
//    s = min(n,m);
//    for(int i=2; i<=s; i++)
//        if((n%i == 0) && (m%i == 0)) max = i;
//
//    if(n == m) cout << max << endl << max*(n/max);
//    else cout << max << endl << max*(n/max)*(m/max);
//}