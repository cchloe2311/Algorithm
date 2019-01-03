#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;

    getline(cin, input);

    for(int i=0; i<input.size()/2; i++)
        if(input[i] != input[input.size()-1-i]){
            cout << "NO";
            return 0;
        }

    cout << "YES";
}