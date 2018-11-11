//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//class TestCase{
//public:
//    int test[3];
//    int strike;
//    int ball;
//    TestCase(string testStr, int strike, int ball){
//        for(int i=0; i<3; i++){
//            test[i] = (int)testStr[i] - '0';
//        }
//        this->strike = strike; this->ball = ball;
//    }
//};
//
//bool isPossible(vector<TestCase> cases, int combination[3]){
//    int check =0;
//    for(int i=0; i<cases.size(); i++){
//        int ball = 0, strike = 0;
//        for(int j=0; j<3; j++)
//            for(int k=0; k<3; k++){
//                if(combination[j] == cases[i].test[k] && j == k){
//                    strike++;
//                    break;
//                }
//                else if(combination[j] == cases[i].test[k] && j != k){
//                    ball++;
//                    break;
//                }
//            }
//        if(ball==cases[i].ball && strike==cases[i].strike) check++;
//    }
//    if(check == cases.size()) return true;
//    else return false;
//}
//
//bool isValidCase(int combination[3]){
//    for(int i=0; i<2; i++){
//        for(int j=i+1; j<3; j++){
//            if(combination[i] == combination[j]) return false;
//            if(combination[i] == 0 || combination[j] == 0) return false;
//        }
//    }
//    return true;
//}
//
//int main(){
//    int candidate = 0;
//
//    int numOfCase;
//    vector<TestCase> cases;
//    cin >> numOfCase;
//
//    for(int i=0; i<numOfCase; i++){
//        string tempTestStr;
//        int tempStrike, tempBall;
//        cin >> tempTestStr >> tempStrike >> tempBall;
//        cases.push_back(TestCase(tempTestStr, tempStrike, tempBall));
//    }
//
//    for(int i=123; i<=987; i++){
//        int temp[3];
//        for(int j=0; j<3; j++){
//            temp[j] = (i % (int)pow(10, j+1)) / (int)pow(10, j);
//        }
// 퍼센테이지가 낮았던 이유 : 같은 숫자가 여러번 나오는 경우, 0이 나오는 경우를 고려하지 않았음
//        if(!isValidCase(temp)) continue;
//        if(isPossible(cases, temp)) candidate++;
//    }
//    cout << candidate;
//}