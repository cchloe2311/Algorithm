#include <iostream>
#include <map>
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;

    map<int, int> m;

    for(int i=0; i<n; i++){
        int input;
        cin >> input;

        if(m.find(input) == m.end()) m.insert({input, 1});
        else m[input]++;
    }

    for(int i=0; i<q; i++){
        int question;
        cin >> question;

        if(m.find(question) == m.end()) cout << 0 << endl;
        else cout << m[question] << endl;
    }
}