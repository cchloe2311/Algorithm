//#include <iostream>
//#include <vector>
//using namespace std;
//
//float isAP(vector<float> testCase){
//    if(testCase[1]-testCase[0] == testCase[2] - testCase[1])
//        return testCase[1] - testCase[0];
//    else return 0.0;
//}
//
//float isGP(vector<float> testCase){
//    if(testCase[1]/testCase[0] == testCase[2]/testCase[1])
//        return testCase[1]/testCase[0];
//    else return 1.0;
//}
//
//int main(){
//    vector<vector<float> > testCase;
//
//    while(1){
//        float a1, a2, a3;
//        cin >> a1 >> a2 >> a3;
//
//        if(a1 == 0 && a2 == 0 && a3 == 0) break;
//
//        vector<float> temp;
//        temp.push_back(a1); temp.push_back(a2); temp.push_back(a3);
//        testCase.push_back(temp);
//    }
//
//    for(int i =0; i<testCase.size(); i++){
//        float check = isAP(testCase[i]);
//        if(check != 0.0){
//            cout << "AP "<< testCase[i][2]+check<< endl;
//            continue;
//        }
//
//        check = isGP(testCase[i]);
//        if(check != 1.0) cout << "GP " << testCase[i][2]*check<<endl;
//    }
//}