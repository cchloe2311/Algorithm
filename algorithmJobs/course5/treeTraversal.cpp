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

    s.push(v[0]);
    isBeen[s.top().id] = 1;

    while(!s.empty()){
        if(isBeen[s.top().id] == 1){
            result.push_back(s.top().id);
            isBeen[s.top().id] = 2;
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
    cout << endl;
}

void inorder(vector<Node> v){
    stack<Node> s;
    vector<int> result;
    int *isBeen = new int[v.size()];
    memset(isBeen, 0, sizeof(int)*v.size());

    s.push(v[0]);
    isBeen[s.top().id] = 1;

    while(!s.empty()){
        if((s.top().leftChild == -1 || isBeen[s.top().leftChild] == 2) && isBeen[s.top().id] != 2){
            result.push_back(s.top().id);
            isBeen[s.top().id] = 2;
        }
        else if(isBeen[s.top().leftChild] == 0){
            isBeen[s.top().leftChild] = 1;
            s.push(v[s.top().leftChild]);
            continue;
        }

        if(s.top().rightChild != -1 && isBeen[s.top().rightChild] == 0){
            isBeen[s.top().rightChild] = 1;
            s.push(v[s.top().rightChild]);
        }else{
            s.pop();
        }
    }

    for(int i=0; i<result.size(); i++) cout << result[i] << " ";
    cout << endl;
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
    inorder(v);
}