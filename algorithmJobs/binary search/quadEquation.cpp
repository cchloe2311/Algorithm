#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int a;
    scanf("%d", &a);

    int low = sqrt(a);
    int high = sqrt(a+1);
    int mid;

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