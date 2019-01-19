#include <iostream>
#include <stack>
using namespace std;

int main(){
    const char OPEN = '(';
    const char CLOSE = ')';

    string str;
    cin >> str;

    stack<int> s;

    for(int i=0; i<str.size(); i++){
        if(str[i] == OPEN) s.push(1);
        else{
            if(s.empty()){
                cout << "NO";
                return 0;
            }
            else s.pop();
        }
    }

    if(!s.empty()) cout << "NO";
    else cout << "YES";
}