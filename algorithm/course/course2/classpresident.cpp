//#include <iostream>
//#include <utility>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main(){
//    pair<int, vector<int> > classPresident;
//    classPresident.first = -1;
//    vector<int> formerClassmate;
//    classPresident.second = formerClassmate;
//
//    int numOfStudent;
//    cin >> numOfStudent;
//    int **formerClass = new int*[numOfStudent];
//    for(int i=0; i<numOfStudent; i++) formerClass[i] = new int[5]; // 1학년, 2학년, 3학년, 4학년, 5학년 반을 기록하기 위해
//
//    for(int i=0; i<numOfStudent; i++)
//        for(int j=0; j<5; j++) cin >> formerClass[i][j];
//
//    for(int i=0; i<numOfStudent; i++){
//        vector<int> tempFormerClassmate;
//        for(int j=0; j<5; j++){ //j학년 때 같은 반이었던 친구들의 수를 기록하기위해
//            for(int k=0; k<numOfStudent; k++){
//                if(formerClass[i][j] == formerClass[k][j])
//                    if(find(tempFormerClassmate.begin(), tempFormerClassmate.end(), k) == tempFormerClassmate.end()){
//                        tempFormerClassmate.push_back(k);
//                }
//            }
//        }
//        if(classPresident.second.size() < tempFormerClassmate.size()){
//            classPresident.first = i;
//            classPresident.second = tempFormerClassmate;
//        }
//    }
//
//    cout << classPresident.first+1;
//}