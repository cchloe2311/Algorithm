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

//void preorder(vector<Node> v){
//
//    stack<Node> s;
//    vector<int> result;
//    int *isBeen = new int[v.size()];
//    memset(isBeen, 0, sizeof(int)*v.size());
//
//    s.push(v[0]);
//    isBeen[s.top().id] = 1;
//
//    while(!s.empty()){
//        if(isBeen[s.top().id] == 1){
//            result.push_back(s.top().id);
//            isBeen[s.top().id] = 2;
//        }
//        if(s.top().leftChild != -1 && isBeen[s.top().leftChild] == 0){
//            isBeen[s.top().leftChild] = 1;
//            s.push(v[s.top().leftChild]);
//            continue;
//        }
//        else if(s.top().rightChild != -1 && isBeen[s.top().rightChild] == 0){
//            isBeen[s.top().rightChild] = 1;
//            s.push(v[s.top().rightChild]);
//            continue;
//        }
//
//        s.pop();
//    }
//
//    for(int i=0; i<result.size(); i++) cout << result[i] << " ";
//    cout << endl;
//}
//
//void inorder(vector<Node> v){
//    stack<Node> s;
//    vector<int> result;
//    int *isBeen = new int[v.size()];
//    memset(isBeen, 0, sizeof(int)*v.size());
//
//    s.push(v[0]);
//    isBeen[s.top().id] = 1;
//
//    while(!s.empty()){
//        if((s.top().leftChild == -1 || isBeen[s.top().leftChild] == 2) && isBeen[s.top().id] != 2){
//            result.push_back(s.top().id);
//            isBeen[s.top().id] = 2;
//        }
//        else if(isBeen[s.top().leftChild] == 0){
//            isBeen[s.top().leftChild] = 1;
//            s.push(v[s.top().leftChild]);
//            continue;
//        }
//
//        if(s.top().rightChild != -1 && isBeen[s.top().rightChild] == 0){
//            isBeen[s.top().rightChild] = 1;
//            s.push(v[s.top().rightChild]);
//        }else{
//            s.pop();
//        }
//    }
//
//    for(int i=0; i<result.size(); i++) cout << result[i] << " ";
//    cout << endl;
//}

void preorderRec(vector<Node> v, int index){
    cout << index << " ";
    if(v[index].leftChild != -1) preorderRec(v, v[index].leftChild);
    if(v[index].rightChild != -1) preorderRec(v, v[index].rightChild);
}

void inorderRec(vector<Node> v, int index){
    if(v[index].leftChild != -1) inorderRec(v, v[index].leftChild);
    cout << index << " ";
    if(v[index].rightChild != -1) inorderRec(v, v[index].rightChild);
}

void postorderRec(vector<Node> v, int index){
    if(v[index].leftChild != -1) postorderRec(v, v[index].leftChild);
    if(v[index].rightChild != -1) postorderRec(v, v[index].rightChild);
    cout << index << " ";
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

    preorderRec(v, 0);
    cout << endl;
    inorderRec(v, 0);
    cout << endl;
    postorderRec(v, 0);
}