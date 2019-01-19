#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

const char OPEN[2] = {'(', '['};\

bool isOpen(char c){
    if(c == OPEN[0] || c == OPEN[1]) return true;
    else return false;
}

int main(){
    string str;
    cin >> str;

    map<char, char> m;
    m.insert({'(', ')'});
    m.insert({'[', ']'});

    vector<string> v;

    for(int i=0; i<str.size(); i++){
        if(isOpen(str[i])){
            v.push_back(string(1, str[i]));
        }
        else{
            int sum = 0;
            while(1){
                if(v.back()[0] < 48 || v.back()[0] > 57){
                    if(m[v.back()[0]] == str[i]){
                        if(sum == 0) sum = 1;

                        if(v.back()[0] == OPEN[0]) v.back() = to_string(sum*2);
                        else v.back() = to_string(sum*3);

                        break;
                    }
                    else{
                        cout << 0;
                        return 0;
                    }
                }
                else{
                    sum += stoi(v.back());
                    v.pop_back();
                }
            }
        }
    }

    int sum = 0;

    for(int i=0; i<v.size(); i++){
        if(v[i][0] >=48 && v[i][0] <=57) sum += stoi(v[i]);
        else{
            sum = 0;
            break;
        }
    }

    cout << sum;
}