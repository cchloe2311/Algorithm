#include <iostream>
#include <vector>

using namespace std;


void getAncestors(vector<int> &v, int *parent){
    if(parent[v[v.size()-1]] != -1) {
        v.push_back(parent[v[v.size()-1]]);
        getAncestors(v, parent);
    }
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    int *parent = new int[n];
    parent[0] = -1;

    for(int i=0; i< n-1; i++){
        int p, c;
        cin >> p >> c;
        parent[c] = p;
    }
    vector<int> ancestorOfX;
    vector<int> ancestorOfY;

    ancestorOfX.push_back(x);
    ancestorOfY.push_back(y);

    getAncestors(ancestorOfX, parent);
    getAncestors(ancestorOfY, parent);

    for(int i=1; i<ancestorOfX.size(); i++)
        for(int j=1; j<ancestorOfY.size(); j++)
            if(ancestorOfX[i] == ancestorOfY[j]){
                cout << ancestorOfX[i];
                return 1;
            }
}