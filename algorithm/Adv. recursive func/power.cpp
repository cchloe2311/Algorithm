#include <iostream>
#include <utility>
#include <math.h>
using namespace std;

#define DIV 10007

//long long getPower(int n, int power){
//    if(power == 0) return 1;
//    else return (n*getPower(n, --power))%DIV;
//}

void makeFunction(int m){
    int power  = 0;

    while(1){
        if(m <= pow(2, power)) break;
        power++;
    }

    int k = power > 0 ? power-1 : power;
    cout << "2^" << k << " + ";

    if(power == 0) return;
    else makeFunction(m-pow(2, --power));

}

int main(){
    int n, m;
    cin >> n >> m;

//    pair<int, int> function = makeFunction(m);
    // 2^k + l으로는 안됨,, 더...

    makeFunction(m);

//    cout << (getPower(pow(n, 2), function.first)*getPower(n, function.second))%DIV;
}