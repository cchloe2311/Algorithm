#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Info{
public:
    int isSame;
    int fullOf;
    int y;
    int x;
    int size;
    Info(int isSame, int fullOf, int y, int x, int size){
        this->isSame = isSame;
        this->fullOf = fullOf;
        this->y= y;
        this->x = x;
        this->size = size;
    }
};
int isSameValue(int **tempMap, int y, int x,int size) {
    int init = tempMap[y][x];
    for(int i=y; i<y+size; i++)
        for(int j=x; j<x+size; j++)
            if(tempMap[i][j] != init) return -1;

    return init;
}

void printHexa(string binary){
}

int main(){
    vector<Info > result;
    int n;
    cin >> n;
    int **map = new int*[n];
    for(int i=0; i<n; i++) map[i] = new int[n];

    for(int i=n-1; i>=0; i--)
        for(int j=0; j<n; j++) cin >> map[i][j];

    queue<int> q;

    int check = isSameValue(map, 0, 0, n);
    if(check == 1 || check == 0){
        result.push_back(Info(0, check, 0, 0, n));
    }
    else{
        result.push_back(Info(1, -1, 0, 0, n));
        q.push(0);
    }

    pair<int, int> quad[4] = {{1,0}, {1,1},
                                {0,0}, {0,1}};
    while(!q.empty()){
        int index = q.front();
        q.pop();
        int size = result[index].size/2;

        for(int i=0; i<4; i++){
            check = isSameValue(map, result[index].y+size*quad[i].first,
                                result[index].x+size*quad[i].second ,size);
            if(check == -1){
                result.push_back(Info(1, -1, result[index].y+size*quad[i].first, result[index].x+size*quad[i].second, size));
                q.push(result.size()-1);
                cout << "(1)";
            }
            else{
                result.push_back(Info(0, check, result[index].y+size*quad[i].first, result[index].x+size*quad[i].second, size));
                cout << "(0," << check << ")";
            }
        }
    }

    cout <<endl;

    string binary = "";
    for(int i=0; i<result.size(); i++){
        if(result[i].isSame == 1) binary += '1';
        else {
            binary += '0';
            binary += to_string(result[i].fullOf);
        }
    }

    cout << binary<<endl;

    printHexa(binary);
}