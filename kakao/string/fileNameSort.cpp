
/**
 * @file theMusic.cpp
 * @data 20219/03/19
 * @author 최서정 github.com/cchloe2311
 * @brief 2018 카카오 신입 공채 3차 코딩 테스트 문제 #3
 */

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class File{
public:
    string strName;
    string header;
    int num;

    File(string strName);

    bool isNum(char ch);
    void toLowwer();
};

File::File(string strName) {
    this->strName = strName;

    int indexPre = 0;
    while(!isNum(strName[indexPre])) {
        indexPre++;
    }

    header = strName.substr(0, indexPre);
    toLowwer();

    int indexPost = indexPre;
    while(isNum(strName[indexPost])) {
        indexPost++;
    }

    num = atoi(strName.substr(indexPre, (indexPost - indexPre + 1)).c_str());
}

void File::toLowwer() {
    for (int i = 0; i < header.size(); i++) {
        if (header[i] >= 65) header[i] = tolower(header[i]);
    }
}

bool File::isNum(char ch) {
    if ((ch >= '0') && (ch <= '9')) return true;
    else return false;
}

bool cmp(const File &u, const File &v) {
    if (u.header == v.header) {
        return u.num < v.num;
    }
    else return u.header < v.header;
}


int main() {
    vector<string> strFiles = {"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"};

    vector<File> files;

    for (int i = 0; i < strFiles.size(); i++) {
        files.push_back(File(strFiles[i]));
    }

    sort(files.begin(), files.end(), cmp);

    for (int i = 0; i < files.size(); i++) {
        cout << files[i].strName << endl;
    }
}