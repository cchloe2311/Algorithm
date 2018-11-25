//#include <iostream>
//#include <algorithm>
//#include <limits.h>
//using namespace std;
//
//int main(){
//    int n;
//    cin >> n;
//
//    int *distance = new int[n-1];
//    int *position = new int[n];
//    int shortestD = INT_MAX;
//
//    cin >> position[0];
//    for(int i=1; i<n; i++){
//        cin >> position[i];
//        distance[i-1] = position[i] - position[i-1];
//        if(distance[i-1] < shortestD) shortestD = distance[i-1];
//    }
//
//    int numOfTree = 0;
//    while(1){
//        int i;
//        for(i=0; i<n-1; i++){
//            if(distance[i]%shortestD != 0){
//                shortestD--;
//                numOfTree = 0;
//                break;
//            }
//            else numOfTree += distance[i]/shortestD-1;
//        }
//        if(i == n-1){
//            cout << numOfTree;
//            return 0;
//        }
//    }
//}