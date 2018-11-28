#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <cstring>

using namespace std;

class Node{
public:
    int id;
    int leftChild;
    int rightChild;
    Node(int id, int leftChild, int rightChild){
        this->id = id;
        this->leftChild = leftChild;
        this->rightChild = rightChild;
    }
};

void preorder(vector<Node> v){

    stack<Node> s;
    vector<int> result;
    int *isBeen = new int[v.size()];
    memset(isBeen, 0, sizeof(int)*v.size());

    int *isConsidered = new int[v.size()];
    memset(isConsidered, 0, sizeof(int)*v.size());

    s.push(v[0]);

//    while(!s.empty()){
//        if(s.top().isBeen == 0){
//            result.push_back(s.top().id);
//            s.top().isBeen = 1;
//        }
//        if(s.top().isChildBeen[0] != -1){
//            s.top().isChildBeen[0] = -1;
//            s.push(v[s.top().leftChild]);
//            continue;
//        }
//        else if(s.top().isChildBeen[1] != -1){
//            s.top().isChildBeen[1] = -1;
//            s.push(v[s.top().rightChild]);
//            continue;
//        }
//
//        s.pop();
//    }

    while(!s.empty()){
        if(isConsidered[s.top().id] == 0){
            result.push_back(s.top().id);
            isConsidered[s.top().id] = 1;
        }
        if(s.top().leftChild != -1 && isBeen[s.top().leftChild] == 0){
            isBeen[s.top().leftChild] = 1;
            s.push(v[s.top().leftChild]);
            continue;
        }
        else if(s.top().rightChild != -1 && isBeen[s.top().rightChild] == 0){
            isBeen[s.top().rightChild] = 1;
            s.push(v[s.top().rightChild]);
            continue;
        }

        s.pop();
    }

    for(int i=0; i<result.size(); i++) cout << result[i] << " ";
}

int main(){
    int n;
    cin >> n;
    vector<Node> v;
    stack<Node> s;
    for(int i=0; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        Node temp(a, b, c);
        v.push_back(temp);
    }

    preorder(v);
}