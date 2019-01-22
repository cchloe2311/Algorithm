#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int findReceiver(stack<int> s){
    int sender = s.top();
    s.pop();
    for(int i=0; i<s.size(); i++){
        if(s.top() >= sender) return s.size();
        else s.pop();
    }
    return 0;
}

int main(){
    int n;
    cin >> n;

    stack<int> s;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        s.push(temp);
    }

    vector<int> result;

    for(int i=0; i<n; i++){
        result.push_back(findReceiver(s));
        s.pop();
    }

    for(int i=result.size()-1; i>=0; i--) cout << result[i] << " ";

}