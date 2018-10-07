#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

int isExistInfo(vector<pair<string, string>> info, string userId){
    if(info.size() == 0) return -1; //  없는 정보임을 의미
    for(int i=0; i<info.size(); i++)
        if(info[i].first == userId) return i;
    return -1;
}

vector<string> solution(vector<string> record) {
    map<string, int> m;
    m.insert(make_pair("Enter", 0));
    m.insert(make_pair("Leave", 1));
    m.insert(make_pair("Change", 2));

    vector<pair<string, int>> trace;
    vector<pair<string, string>> info; // userID, nickname 순서의 pair
    for(int i=0; i<record.size(); i++){
        // "Enter uid1234 Muzi"
        string state, uId, nickname;
        stringstream ss(record[i]);
        ss >> state; // 맨 처음 [state]를 잘라옴
        ss >> uId;
        ss >> nickname;
        int check;
        switch(m.find(state)->second){
            case 0: // Enter
                check = isExistInfo(info,uId);
                if(check == -1)
                    info.push_back(make_pair(uId, nickname));
                else {
                    if (info[check].second != nickname) info[check].second = nickname;
                }
                trace.push_back(pair<string ,int>(uId, m.find(state)->second));
                break;
            case 1: // Leave
                trace.push_back(pair<string ,int>(uId, m.find(state)->second));
                break;
            case 2: // Change
                info[isExistInfo(info, uId)].second = nickname;
                break;
        }

    }
    vector<string> answer;
    for(int i=0; i<trace.size(); i++){
        if(trace[i].second == 0){
            string output = info[isExistInfo(info, trace[i].first)].second + "님이 들어왔습니다.";
            answer.push_back(output);
        }
        else{
            string output = info[isExistInfo(info, trace[i].first)].second + "님이 나갔습니다.";
            answer.push_back(output)
        }
    }
    return answer;
}