#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;

    getline(cin, input);

    // 대문자 아스키코드 > 65~90
    // 소문자 아스키코드 > 97~122
    // 따라서, 소문자 = 대문자 + 32
    //        대문자 = 소문자 - 32

    for(int i=0; i<input.length(); i++){
        if(char(97) <= input[i] && input[i] <= 122){ // 소문자라면
            cout << char(input[i] - 32);
        }
        else if(char(65) <= input[i] && input[i] <= 90){  // 대문자라면
            cout << char(input[i] + 32);
        }
        else cout << input[i];
    }
}