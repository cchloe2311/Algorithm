#include <iostream>
#include <string>

using namespace std;

int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);

    int index = 0;

    for(int i=0; i<a.size(); i++){
        if(a[i] == b[index]){
            if(++index == b.size()){
                cout << "YES";
                return 0;
            }
        }
        else if(index != 0) index = 0;
    }

    cout << "NO";
}