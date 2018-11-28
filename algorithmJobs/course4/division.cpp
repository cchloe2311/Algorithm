//#include <iostream>
//#include <vector>
//#include <utility>
//#include <algorithm>
//using namespace std;
//
//bool isInOutput(vector<vector<int> > output, vector<int> &cmp){
//    if(cmp[0] == 0) cmp.erase(cmp.begin());
//
//    for(int i=0; i<output.size(); i++){
//        if(cmp.size() != output[i].size()) continue;
//        sort(output[i].begin(), output[i].end());
//        reverse(output[i].begin(), output[i].end());
//        sort(cmp.begin(), cmp.end());
//        reverse(cmp.begin(), cmp.end());
//
//        if(cmp == output[i]) return true;
//    }
//    return false;
//}
//
//void getOutput(vector<vector<vector<int> > > &output, int n, int cur){
//    vector<pair<int,int> > tempOp;
//    for(int i=0; i<=cur/2; i++) tempOp.push_back(make_pair(cur-i, i));
//
//    for(int i=0; i<tempOp.size(); i++){
//        for(int j=0; j<output[tempOp[i].first].size(); j++){
//            vector<int> tempV;
//            for(int k=0; k<output[tempOp[i].first][j].size(); k++)
//                tempV.push_back(output[tempOp[i].first][j][k]);
//            tempV.push_back(tempOp[i].second);
//            if(!isInOutput(output[cur], tempV)) {
//                output[cur].push_back(tempV);
//            }
//        }
//        for(int j=0; j<output[tempOp[i].second].size(); j++){
//            vector<int> tempV;
//            for(int k=0; k<output[tempOp[i].second][j].size(); k++)
//                tempV.push_back(output[tempOp[i].second][j][k]);
//            tempV.push_back(tempOp[i].first);
//            if(!isInOutput(output[cur], tempV)) {
//                output[cur].push_back(tempV);
//            }
//        }
//    }
//
//    if(cur != n) getOutput(output, n, ++cur);
//}
//
//int main(){
//    int n;
//    cin >> n;
//
//    vector<vector<vector<int> > > dp;
//    dp.resize(n+1);
//    vector<int> temp0, temp1;
//    temp0.push_back(0);
//    temp1.push_back(1);
//    dp[0].push_back(temp0);
//    dp[1].push_back(temp1);
//
//    getOutput(dp, n, 2);
//
//
//    sort(dp[n].begin(), dp[n].end());
//    reverse(dp[n].begin(), dp[n].end());
//    for(int i=1; i<dp[n].size(); i++){
//        cout << dp[n][i][0];
//        for(int j=1; j<dp[n][i].size(); j++) cout << "+"<<dp[n][i][j];
//        cout << endl;
//    }
//    cout << dp[n].size()-1;
//}