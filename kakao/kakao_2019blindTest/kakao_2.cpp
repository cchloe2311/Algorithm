//
// Created by 최서정 on 2018. 10. 7..
//

#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class StageInfo{
public:
    int stageNum;
    float upper;
    float value;
    StageInfo(int stageNum){
        this->stageNum = stageNum;
        this->upper = 0;
    }
    bool operator <(const StageInfo &a) const{
        return this->value > a.value;
    }
};

vector<int> solution(int N, vector<int> stages) {
    vector<StageInfo> stageInfoV;
    stageInfoV.push_back(StageInfo(0));
    for(int i=1; i<=N+1; i++) stageInfoV.push_back(StageInfo(i));
    for(int i=0; i<stages.size(); i++) stageInfoV[stages[i]].upper++;

    int lowwer = stages.size();
    stageInfoV[1].value = stageInfoV[1].upper/lowwer;
    for(int i=2; i<=N; i++){
        lowwer -= stageInfoV[i-1].upper;
        stageInfoV[i].value = stageInfoV[i].upper/lowwer;
    }

    stable_sort(stageInfoV.begin()+1, stageInfoV.end()-1);

    vector<int> answer;
    for(int i=1; i<=N; i++) answer.push_back(stageInfoV[i].stageNum);

    return answer;
}