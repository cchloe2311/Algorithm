#include <iostream>
#include <string>
#include <utility>

using namespace std;

string compressString(string input, int index){
    int count = 1;

    if(index == input.size()) return "";

    index++;
    while(1){
        if(index == input.size() || input[index-1] != input[index]){
            string output = "";

            if(count == 1) output.push_back(input[index-1]);
            else output.append(to_string(count)+input[index-1]);
            return output.append(compressString(input, index));
        }
        else {
            index++; count++;
        }
    }
}

string compressString(string input){
    string output = "";

    pair<char, int> p;
    p = make_pair(input[0], 1);
    for(int i=1; i<input.size(); i++){
        if(p.first == input[i]) p.second++;
        else{
            if(p.second == 1) output.push_back(p.first);
            else output.append(to_string(p.second)+p.first);

            p.first = input[i];
            p.second = 1;
        }
    }

    if(p.second == 1) output.push_back(p.first);
    else output.append(to_string(p.second)+p.first);

    return output;
}

int main(){
    string input;
    getline(cin, input);

    cout << compressString(input, 0)<< endl;
    cout << compressString(input);
}