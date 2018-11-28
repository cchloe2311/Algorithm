#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node{
public:
    int id;
    int leftChild;
    int rightChild;
    int isBeen;
    int isChildBeen[2];
    Node(int id, int leftChild, int rightChild){
        this->id = id;
        this->leftChild = leftChild;
        this->rightChild = rightChild;
        isBeen = 0;
        isChildBeen[0] = leftChild;
        isChildBeen[1] = rightChild;
    }
};

void preorder(vector<Node> v){

    stack<Node> s;
    vector<int> result;

    s.push(v[0]);

    while(!s.empty()){
        if(s.top().isBeen == 0){
            result.push_back(s.top().id);
            s.top().isBeen = 1;
        }
        if(s.top().isChildBeen[0] != -1){
            s.top().isChildBeen[0] = -1;
            s.push(v[s.top().leftChild]);
            continue;
        }
        else if(s.top().isChildBeen[1] != -1){
            s.top().isChildBeen[1] = -1;
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