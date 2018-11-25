//
// Created by 최서정 on 2018. 9. 17..
//

#include <iostream>
#include <map>
using namespace std;
class Queue{
public:
    int *arr;
    int front;
    int back;
    int size;
    int howManyE;
    Queue(int size);
    void push(int value);
    void pop();
};

Queue::Queue(int size) {
    arr = new int[size+1];
    front = back = 0;
    this->size = size+1;
    howManyE = 0;
}

void Queue::push(int value) {
    if(front%size != (back+1)%size){    // not full
        back = (back+1)%size;
        arr[back] = value;
        howManyE++;
    }
}

void Queue::pop(){
    if(front != back){
        front = (front+1)%size;
        cout << arr[front] << endl;
        arr[front] = NULL;
        howManyE--;
    }
    else cout << -1 << endl;
}

int main(){
    int order;
    cin >> order;

    Queue q(order);

    map<string, int> m;
    m.insert(make_pair("pop", 1));
    m.insert(make_pair("size", 2));
    m.insert(make_pair("empty", 3));
    m.insert(make_pair("front", 4));
    m.insert(make_pair("back", 5));

    cin.ignore();
    for(int i=1; i<=order; i++){
        string input;
        getline(cin, input);
        switch (m.find(input)->second){
            case 1: // pop
                q.pop();
                break;
            case 2: // size
                cout << q.howManyE << endl;
                break;
            case 3: // empty
                if(q.front == q.back) cout << 1 << endl;
                else cout << 0 << endl;
                break;
            case 4: // front
                if(q.front == q.back) cout << -1 << endl;
                else cout << q.arr[(q.front+1)%q.size] << endl;
                break;
            case 5:
                if(q.front == q.back) cout << -1 << endl;
                else cout << q.arr[q.back] << endl;
                break;
            default:
                int value = stoi(input.substr(5));
                q.push(value);
                break;
        }
    }
}