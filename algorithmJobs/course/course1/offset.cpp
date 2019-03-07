//#include <iostream>
//#include <utility>
//using namespace std;
//
//#define RANGE_X 5
//#define RANGE_Y 5
//
//bool isInRange(int y, int x){
//    if(x <0) return false;
//    if(x >= RANGE_X) return false;
//
//    if(y <0) return false;
//    if(y >= RANGE_Y) return false;
//
//    return true;
//}
//
//int main(){
//    pair<int, int> position[4];
//    position[0] = make_pair(-1,0);
//    position[1] = make_pair(0,1);
//    position[2] = make_pair(1,0);
//    position[3] = make_pair(0,-1);
//
//    int input[5][5];
//    for(int i=0; i<RANGE_Y; i++)
//        for(int j=0; j<RANGE_X; j++) cin >> input[i][j];
//
//    for(int i=0; i<RANGE_Y; i++){
//        for(int j=0; j<RANGE_X; j++){
//            int sum =0;
//            for(int k=0; k<4; k++){
//                if(isInRange(i+position[k].second, j+position[k].first)){
//                    if(input[i+position[k].second][j+position[k].first] > input[i][j]) sum++;
//                    else break;
//                }
//                else sum++;
//            }
//            if(sum == 4) input[i][j] = -1;
//        }
//    }
//
//    for(int i=0; i<RANGE_Y; i++) {
//        for (int j = 0; j < RANGE_X; j++) {
//            if (input[i][j] == -1) cout << "* ";
//            else cout << input[i][j] << " ";
//        }
//        cout << endl;
//    }
//}