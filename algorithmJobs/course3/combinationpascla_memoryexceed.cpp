//#include <iostream>
//#include <queue>
//#include <utility>
//using namespace std;
//
//int main(){
//    queue<pair<int, int> > q;
//    int n, m;
//    cin >> n >> m;
//    q.push(make_pair(n, m));
//    int combination = 0;
//
//    while(!q.empty()){
//        pair<int, int> front;
//        front = q.front();
//        q.pop();
//
//        if(front.first-1 == front.second) combination++;
//        else if(front.second == 0) combination++;
//        else q.push(make_pair(front.first-1, front.second));
//
//        if(front.first-1 == front.second-1) combination++;
//        else if(front.second-1 == 0) combination++;
//        else q.push(make_pair(front.first-1, front.second-1));
//    }
//
//    cout << combination;
//}