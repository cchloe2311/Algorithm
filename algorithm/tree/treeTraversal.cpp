#include <iostream>
using namespace std;

class Node{
public:
    int value;
    int leftChild;
    int rightChild; // store its index
    void initNode(int value, int leftChild, int rightChild){
        this->value = value;
        this->leftChild = leftChild;
        this->rightChild = rightChild;
    }
};

void preorderRec(Node *tree, int index){
    cout << index << " ";
    if(tree[index].leftChild != -1) preorderRec(tree, tree[index].leftChild);
    if(tree[index].rightChild != -1) preorderRec(tree, tree[index].rightChild);
}

void midorderRec(Node *tree, int index){
    if(tree[index].leftChild != -1) midorderRec(tree, tree[index].leftChild);
    cout << index << " ";
    if(tree[index].rightChild != -1) midorderRec(tree, tree[index].rightChild);
}

void postorderRec(Node *tree, int index){
    if(tree[index].leftChild != -1) postorderRec(tree, tree[index].leftChild);
    if(tree[index].rightChild != -1) postorderRec(tree, tree[index].rightChild);
    cout << index << " ";
}

int main(){
    int n;
    cin >> n;

    Node *tree = new Node[n];

    for(int i=0; i<n; i++){
        int value, leftChild, rightChild;
        cin >> value >> leftChild >> rightChild;
        tree[i].initNode(value, leftChild, rightChild);
    }

    preorderRec(tree, 0);
    cout << endl;
    midorderRec(tree, 0);
    cout << endl;
    postorderRec(tree, 0);
}