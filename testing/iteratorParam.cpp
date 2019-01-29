#include <iostream>
#include <vector>
using namespace std;

void test(vector<int>::iterator a, vector<int>::iterator b){
    int temp = *a;

    *a = *b;
    *b = temp;
}

int main(){
    vector<int> v(2, 1);
    v.push_back(3);

    for(int i=0; i<3; i++) cout << v[i] << " ";
    cout << endl;

    test(v.begin(), v.end()-1);

    for(int i=0; i<3; i++) cout << v[i] << " ";
    cout << endl;
}