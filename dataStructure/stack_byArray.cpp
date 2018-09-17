////
//// Created by 최서정 on 2018. 9. 15..
////
//
//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//
//class Stack{
//public:
//    int *arr;
//    int top;
//    Stack(int size);
//    void push(int value);
//    void pop();
//};
//
//Stack::Stack(int size) {
//    arr = new int[size];
//    top = -1;
//}
//void Stack::push(int value) {
//    arr[++top] = value;
//}
//void Stack::pop(){
//    if(top != -1){
//        cout << arr[top] << endl;
//        arr[top--] = NULL;
//    }
//    else cout << -1 << endl;
//}
//
//
//int main(){
//    int order;
//    cin >> order;
//
//    Stack st(order);
//
//    map<string, int> m;
//    m.insert(make_pair("pop", 1));
//    m.insert(make_pair("size", 2));
//    m.insert(make_pair("empty", 3));
//    m.insert(make_pair("top", 4));
//
//    cin.ignore();
//    for(int i=1; i<=order; i++){
//        string input;
//        getline(cin, input);
//        switch (m.find(input)->second){
//            case 1: // pop
//                st.pop();
//                break;
//            case 2: // size
//                cout << st.top+1 << endl;
//                break;
//            case 3: // empty
//                if(st.top == -1) cout << 1 << endl;
//                else cout << 0 << endl;
//                break;
//            case 4: // top
//                if(st.top == -1) cout << -1 << endl;
//                else cout << st.arr[st.top] << endl;
//                break;
//            default:
//                int value = stoi(input.substr(5));
//                st.push(value);
//                break;
//        }
//    }
//}