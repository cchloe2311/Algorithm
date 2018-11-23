//#include <iostream>
//using namespace std;
//
//int main(){
//    int op[3] = {1, 0, -1};
//
//    int dest, start;
//    cin >> start >> dest;
//
//    int cur = start;
//    int k = 0;
//    int numOfMovement=0;
//    bool isDone = false;
//    while(!isDone){
//        for(int i=0; i<3; i++){
//            if(cur + (k+op[i]) < dest){
//                cur += k+op[i];
//                k += op[i];
//                numOfMovement++;
//                break;
//            }
//            else if((cur + (k+op[i]) == dest) && (k+op[i] == 1)){
//                numOfMovement++;
//                isDone = true;
//                break;
//            }
//        }
//    }
//    cout<< numOfMovement;
//}