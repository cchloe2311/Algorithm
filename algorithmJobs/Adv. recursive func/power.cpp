#include <iostream>

using namespace std;

#define DIV 10007

long long getPower(int n, long long k){
    if(--k == 0) return n;
    else return n*(getPower(n, k)%DIV)%DIV;
}

int main(){
    long long n, m;
    cin >> n >> m;

    cout << getPower(n, m%DIV);
}