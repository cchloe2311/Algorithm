#include <iostream>
#include <math.h>
using namespace std;

int main(){
    long long a;
    cin >> a;

    long long low = sqrt(a);
    long long high = sqrt(a+1);
    long long mid;

    while(1){
        mid = (low+high)/2;

        if(mid*(mid+1) <= a && (mid+1)*(mid+2) > a){
            cout << mid;
            break;
        }
        else if(mid*(mid+1) < a) low = mid+1;
        else high = mid-1;
    }
}