//#include <iostream>
//using namespace std;
//
//int main(){
//    long long n,m;
//    long long s, max = 1;
//    cin >> n >> m;
//
//    if(n == 0 || m == 0){ // exception
//        cout << 0;
//        return 0;
//    }
//
//
//    if(n > m) s = m;
//    else s = n;
//
//    for(int i=2; i<=s; i++)
//        if((n%i == 0) && (m%i == 0)) max = i; // 최대 공약수
//
//    if(n == m) cout << (max*(n/max));
//    else cout << (max*(n/max)*(m/max));
//}