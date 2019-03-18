
/**
 * @file theMusic.cpp
 * @data 20219/03/18
 * @author 최서정 github.com/cchloe2311
 * @brief 2018 카카오 신입 공채 3차 코딩 테스트 문제 #4
 */

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

vector<string> spliteSheet(string strSheet);

class MusicInfo{
public:
    int duration;
    string title;
    vector<string> sheet;

    MusicInfo(string startTime, string endTime, string title, string strSheet);

    bool isMatch(vector<string> sheet);
};

MusicInfo::MusicInfo(string startTime, string endTime, string title, string strSheet) {
    string tempStart = startTime.substr(0, 2);
    string tempEnd = endTime.substr(0, 2);
    duration = (atoi(tempEnd.c_str()) - atoi(tempStart.c_str())) * 60;

    tempStart = startTime.substr(3);
    tempEnd = endTime.substr(3);
    duration += (atoi(tempEnd.c_str()) - atoi(tempStart.c_str()));

    this->title = title;
    this->sheet = spliteSheet(strSheet);
}

bool MusicInfo::isMatch(vector<string> inputSheet) {
    vector<int> startIndex;

    for (int i = 0; i < sheet.size(); i++) {
        if (sheet[i] == inputSheet[0]) startIndex.push_back(i);
    }

    for (int i = 0; i < startIndex.size(); i++) {
        for (int j = 0; j < inputSheet.size(); j++) {
            if (sheet[(startIndex[i] + j) % sheet.size()] != inputSheet[j]) break;
            else if (j == (inputSheet.size() - 1)) return true;
        }
    }

    return false;
}

bool cmp(const MusicInfo &u, const MusicInfo &v) {
    return u.duration > v.duration;
}

vector<string> spliteSheet(string strSheet) {
    vector<string> sheet;

    for (int i = 0; i < strSheet.size(); i++) {
        if(strSheet[i] == '#') {
            sheet.back() += '#';
        }
        else {
            string temp(1, strSheet[i]);
            sheet.push_back(temp);
        }
    }

    return sheet;
}

int main() {
    string strSheet = "ABC";

    MusicInfo test = MusicInfo("02:59", "03:14", "HELLO", "C#DEFGAB");
    MusicInfo test2 = MusicInfo("04:00", "04:05", "WORLD", "ABCDEF");
    vector<MusicInfo> musicInfos = {test, test2};

    vector<string> sheet = spliteSheet(strSheet);

    vector<MusicInfo> matchMusics;
    for (int i = 0; i < musicInfos.size(); i++) {
        if (musicInfos[i].isMatch(sheet)) {
            matchMusics.push_back(musicInfos[i]);
        }
    }

    sort(matchMusics.begin(), matchMusics.end(), cmp);

    if (matchMusics.size() > 0) cout <<  matchMusics[0].title;
    else cout << "(None)";
}