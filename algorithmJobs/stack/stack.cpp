#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define PUSH 1
#define POP 2
#define TOP 3

class Stack{
    int *stack;
    int topIndex;
    int size;
public:
    Stack(int size){
        this->size = size;
        stack = new int[size];
        topIndex = -1;
    }
    bool push(int n);
    bool pop();
    int top();
};

bool Stack::push(int n) {
    if(topIndex == size-1) return false;
    else{
        stack[++topIndex] = n;
        return true;
    }
}

bool Stack::pop() {
    if(topIndex == -1) return false;
    else{
        stack[topIndex--] = NULL;
        return true;
    }
}

int Stack::top() {
    if(topIndex == -1) return -1;
    else return stack[topIndex];
}


int main(){
    int n, m;
    cin >> n >> m;

    Stack s(n);
    vector<string> result;


    for(int i=0; i<m; i++){
        int cal, num;
        cin >> cal;

        switch(cal){
            case PUSH :{
                cin >> num;
                if(!s.push(num)) result.push_back("Overflow");
                break;
            }
            case POP :{
                if(!s.pop()) result.push_back("Underflow");
                break;
            }
            case TOP :{
                int top = s.top();
                if(top == -1) result.push_back("NULL");
                else result.push_back(to_string(top));
                break;
            }
        }
    }

    for(int i=0; i<result.size(); i++) cout << result[i]<< endl;
}