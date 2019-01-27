#include <iostream>

using namespace std;

#define DIV 10007

long long getPower(int n, int k){
    if(--k == 0) return n;
    else return n*getPower(n, k)%DIV;
}

int main(){
    long long n, m;
    cin >> n >> m;

    cout << getPower(n, m);
}