#include <iostream>
using namespace std;

int getRange(int a){
    int range = 2;

    while(range*(range+1) < a)
        range *= 2;

    return range;
}

int main(){
    int a;
    scanf("%d", &a);

    int low = 1;
    int high = getRange(a);

    while(1){
        int mid = (low+high)/2;

        if(mid*(mid+1) <= a && (mid+1)*(mid+2) > a){
            cout << mid;
            break;
        }
        else if(mid*(mid+1) < a) low = mid+1;
        else high = mid-1;
    }
}