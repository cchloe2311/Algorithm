#include <string>
#include <vector>
#include <iostream>

using namespace std;

string getConvertedMelody(string orgMelody, int playedMin);

class MusicInfo {
public:
    int playedMin;
    string title;
    string melody;

    MusicInfo(string startTime, string endTime, string title, string melody) {
        setPlayedMin(startTime, endTime);
        this->title = title;

        this->melody = getConvertedMelody(melody, playedMin);
    }

    void setPlayedMin(string startTime, string endTime);
};

void MusicInfo::setPlayedMin(string startTime, string endTime) {
    playedMin = (atoi(endTime.substr(0, 2).c_str()) - atoi(startTime.substr(0, 2).c_str())) * 60;
    playedMin += atoi(endTime.substr(3, 2).c_str());
    playedMin -= atoi(startTime.substr(3, 2).c_str());
}

string getConvertedMelody(string orgMelody, int playedMin) {
    string melody = "";
    int melodyIndex = 0;

    for (int i = 0; i < playedMin; i++) {
        string part;
        int sum = (orgMelody[(melodyIndex + 1) % orgMelody.length()] == '#') ? 2 : 1;

        part = orgMelody.substr(melodyIndex, sum);
        melodyIndex = (melodyIndex + sum) % orgMelody.length();

        if (sum == 1) part += ".";

        melody += part;
    }

    return melody;
}

int getPlayedMin(string m) {
    int min = 0;

    for (int i = 0; i < m.length(); i++) {
        if (m[i] != '#') min++;
    }

    return min;
}

string solution(string m, vector<string> musicinfos) {
    string title = "(None)";
    int playedMin = 0;

    m = getConvertedMelody(m, getPlayedMin(m));

    for (auto iter = musicinfos.begin(); iter < musicinfos.end(); iter++) {
        string delimiter = ",";
        size_t pos = 0;
        vector<string> token;

        while ((pos = (*iter).find(delimiter)) != string::npos) {
            token.push_back((*iter).substr(0, pos));
            (*iter).erase(0, pos + delimiter.length());
        }
        token.push_back((*iter));

        MusicInfo musicInfo(token[0], token[1], token[2], token[3]);
        cout << musicInfo.melody << endl;
        if ((playedMin < musicInfo.playedMin) && (musicInfo.melody.find(m) != -1)) {
            playedMin = musicInfo.playedMin;
            title = musicInfo.title;
        }
    }

    return title;
}

int main() {
//    cout << solution(
////            "ABCDEFG",
////            {"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"}
////    );

//    cout << solution(
//            "ABC",
//            {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"}
//    );

    cout << solution(
            "CC#BCC#BCC#BCC#B",
            {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"}
    );
}