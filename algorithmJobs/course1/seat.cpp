//#include <iostream>
//using namespace std;
//
//int main(){
//    long long c,r;
//    cin >> c >> r;
//    long long goal;
//    cin >> goal;
//    if(goal > c*r){
//        cout << "0";
//        return 0;
//    }
//    int opIndex = 0;
//    long long value =0, sub = 0;
//
//    int op[2] = {1, -1};
//    long long position[2] = {1,0}; // x, y
//    while(1){
//        position[1] = position[1] + op[opIndex]*(r - sub);
//        value += r - sub;
//        if(value == goal) break;
//        else if (value > goal){
//            opIndex = (opIndex+1)%2;
//            position[1] += op[opIndex]*(value-goal);
//            break;
//        }
//        sub++;
//        position[0] = position[0] + op[opIndex]*(c - sub);
//        value += c - sub;
//        if(value == goal) break;
//        else if (value > goal){
//            opIndex = (opIndex+1)%2;
//            position[0] += op[opIndex]*(value-goal);
//            break;
//        }
//        opIndex = (opIndex+1)%2;
//    }
//    cout << position[0] << " "<< position[1];
//}