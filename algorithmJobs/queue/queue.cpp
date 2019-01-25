#include <iostream>
#include <vector>

using namespace std;

#define PUSH 1
#define POP 2
#define FRONT 3

class Queue{
    int size;
    int rear;
    int front;
    int *queue;
public:
    Queue(int size){
        this->size = size;
        queue = new int[size];

        rear = -1;
        front = -1;
    }

    bool push(int n);
    bool pop();
    int getFront();
    bool isFull();
    bool isEmpty();
};

bool Queue::push(int n) {
    if(isFull()) return false;

    rear = (rear+1)%size;
    queue[rear] = n;
    return true;
}

bool Queue::pop() {
    if(front == rear) return false;

    front = (front+1)%size;
    queue[front] = NULL;
    return true;
}

int Queue::getFront() {
    return queue[(front+1)%size];
}

bool Queue::isFull() {
    if((rear+1)%size == front) return true;
    else return false;
}

bool Queue::isEmpty() {
    if(rear == front) return true;
    else return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    static string OVERFLOW = "Overflow";
    static string UNDERFLOW = "Underflow";
    static string null = "NULL";

    Queue q(n);

    vector<string> result;

    for(int i=0; i<m; i++){
        int op, qInput;
        string qOutput;
        cin >> op;

        switch(op){
            case PUSH:{
                cin >> qInput;
                if(!q.push(qInput)) result.push_back(OVERFLOW);
            }
            case POP:{
                if(!q.pop())result.push_back(UNDERFLOW);
            }
            case FRONT:{
                if(q.isEmpty()) result.push_back(null);
                else result.push_back(to_string(q.getFront()));
            }
        }
    }

    for(int i=0; i<result.size(); i++) cout << result[i] << endl;
}