#include <iostream>
#include <string>
#include <vector>

using namespace std;

void sortVec(vector<string> &v, int n){
    int min = n;
    for(int i=n+1; i<v.size(); i++){
        if(v[min] > v[i]) min = i;
    }
    string temp = v[min];
    v[min] = v[n];
    v[n] = temp;

    if(++n == v.size()-1) return;
    else sortVec(v, n);
}

int main(){
    int numOfcase;
    cin >> numOfcase;

    cin.ignore();

    vector<string> cases;

    for(int i=0; i<numOfcase; i++){
        string temp;
        getline(cin, temp);
        cases.push_back(temp);
    }

    sortVec(cases, 0);

    for(int i=0; i<numOfcase; i++)
        cout << cases[i]<< endl;
}