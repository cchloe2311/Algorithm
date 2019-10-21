#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Song {
public:
    int id;
    int play;
};

class Genre {
public:
    string name;
    int plays;
};

bool cmpSong(const Song &a, const Song &b) {
    if (a.play != b.play) return a.play > b.play;
    else return a.id < b.id;
}

bool cmpGenre(Genre a, Genre b) {
    return a.plays > b.plays;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, vector<Song>> m;

    for (int i = 0; i < genres.size(); i++) {
        Song newSong;
        newSong.id = i;
        newSong.play = plays[i];

        if (m.count(genres[i]) == 0) {
            vector<Song> tempV;
            tempV.push_back(newSong);

            m.insert({genres[i], tempV});
        }
        else {
            (*m.find(genres[i])).second.push_back(newSong);
        }
    }

    vector<Genre> v;

    for (auto it = m.begin(); it != m.end(); it++) {
        sort(it->second.begin(), it->second.end(), cmpSong);

        int playSum = 0;

        for (int i = 0; i < it->second.size(); i++) {
            playSum += it->second[i].play;
        }

        Genre newGenre;
        newGenre.name = it->first;
        newGenre.plays = playSum;

        v.push_back(newGenre);
    }

    sort(v.begin(), v.end(), cmpGenre);

    for (int i = 0; i < v.size(); i++) {
        int index = 0;
        while (index < (*m.find(v[i].name)).second.size() && index <= 1) {
            answer.push_back((*m.find(v[i].name)).second[index++].id);
        }
    }

    return answer;
}

int main() {
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};

    vector<int> res = solution(genres, plays);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\t";
    }
}