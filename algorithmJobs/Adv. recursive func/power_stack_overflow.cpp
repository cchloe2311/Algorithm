#include <iostream>

using namespace std;

#define DIV 10007

long long getPower(long long n, long long k){
    if(k == 0) return 1;
    else return (n*getPower(n, --k))%DIV;
} // 이렇게 생으로 재귀를 돌리다보면 stack overflow가 나서 runtime error가 발생함!!

int main(){
    long long n, m;
    cin >> n >> m;

    cout << getPower(n, m);
}