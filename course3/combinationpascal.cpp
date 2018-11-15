//#include <iostream>
//using namespace std;
//
//int main(){
//    int n, m;
//    cin >> n >> m;
//    int **arr = new int*[n+1];
//    for(int i=0; i<n+1; i++) arr[i] = new int[m+1];
//
//    for(int i=0; i<=n; i++){
//        for(int j=0; j<=i; j++){
//            if(i == j) arr[i][j] = 1;
//            else if(j == 0) arr[i][j] = 1;
//            else arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
//        }
//    }
//    cout << arr[n][m];
//}