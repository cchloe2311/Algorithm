//
///**
// * @file dartGame.cpp
// * @data 20219/03/17
// * @author 최서정 github.com/cchloe2311
// * @brief 2017 카카오 신입 공채 1차 코딩 테스트 문제 #2
// */
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <stdlib.h>
//#include <map>
//#include <math.h>
//
//using namespace std;
//
//#define TIME 3
//
//void calScore(vector<int> &scores, char op) {
//    map<char, int> bonus;
//    bonus.insert({'S', 1});
//    bonus.insert({'D', 2});
//    bonus.insert({'T', 3});
//
//    static char STAR = '*';
//    static char OOPS = '#';
//
//    if (bonus.find(op) == bonus.end()) {
//        if (op == STAR) {
//            scores.back() *= 2;
//            if (scores.size() > 1) scores[scores.size() - 2] *= 2;
//        }
//        else if (op == OOPS) {
//            scores.back() *= -1;
//        }
//    }
//    else {
//        scores.back() = pow(scores.back(), bonus[op]);
//    }
//}
//
//int main() {
//    string input;
//    cin >> input;
//
//    vector<int> scores;
//
//    for (int i = 0; i < input.size(); i++) {
//        if ((input[i] >= 48) && (input[i] <= 57)) {
//            if ((input[i] == '0') && (input[i - 1] == '1')) {
//                scores.back() = 10;
//            }
//            else scores.push_back(input[i] - 48);
//        }
//        else {
//            calScore(scores, input[i]);
//        }
//    }
//
//    int sum = 0;
//    for (int i = 0; i < TIME; i++) {
//        sum += scores[i];
//    }
//
//    cout << sum;
//}