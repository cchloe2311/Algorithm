//#include <iostream>
//using namespace std;
//
//int main(){
//    int n;
//    cin >> n;
//
//    int **sumArr = new int*[n];
//    for(int i=0; i<n; i++) sumArr[i] = new int[n];
//    int *seqence = new int[n];
//
//    for(int i=0; i<n; i++)
//        for(int j=0; j<n; j++) cin >> sumArr[i][j];
//
//    for(int i=n-3; i>=0; i--){
//        seqence[i] = (sumArr[i][n-2] + sumArr[i][n-1] - sumArr[n-2][n-1])/2;
//    }
//
//    seqence[n-2] = (sumArr[n-3][n-2] - sumArr[n-3][n-1] + sumArr[n-2][n-1])/2;
//    seqence[n-1] = (sumArr[n-3][n-1] - sumArr[n-3][n-2] + sumArr[n-2][n-1])/2;
//
//    for(int i=0; i<n; i++) cout << seqence[i] << " ";
//}