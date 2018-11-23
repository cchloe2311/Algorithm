#include <iostream>
#include <vector>
#include <utility>
#include <limits.h>
using namespace std;

class Point{
public:
    int seqNum;
    int jump;
    Point(int seqNum, int jump){
        this->seqNum = seqNum; this->jump = jump;
    }
};

int main(){
    int op[3] = {1, 0, -1};

    int startPoint, endPoint;
    cin >> startPoint >> endPoint;
    endPoint;

    vector<Point> *path = new vector<Point>[endPoint-startPoint+1];
    path[startPoint+1-startPoint].push_back(Point(1, 1));

    for(int i=1; i<endPoint-startPoint; i++){
        for(int j=0; j<path[i].size(); j++)
            for(int k=0; j<3; k++)
                if(i+startPoint+path[i][j].jump + op[k] <= endPoint-1){
                    path[i+path[i][j].jump + op[k]]
                            .push_back(Point(path[i][j].seqNum+1, path[i][j].jump + op[k]));
                }
    }

    int minPath = INT_MAX;
    for(int i=0; i<path[endPoint-1-startPoint].size(); i++){
        if(path[endPoint-1-startPoint][i].seqNum+1 < minPath)
            minPath = path[endPoint-1-startPoint][i].seqNum+1;
    }

}