#include <iostream>
#include <utility>
#include <string.h>
#include <algorithm>
using namespace std;

long long getSum(long long *sub, long long n){
    long long sum = 0;
    for(long long i=0; i<n; i++) sum+=sub[i];
    return sum;
}

void setSub(long long *tree, long long *sub, long long mid, long long n){
    for(int i=0; i<n; i++) {
        long long tempSum = tree[i] - mid;
        if(tempSum > 0) sub[i] = tree[i] - mid;
        else sub[i] = 0;
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    long long *tree =  new long long[n];
    long long *sub = new long long[n];

    for(int i=0; i<n; i++) cin >> tree[i];

    long long low = 0;
    long long high = *max_element(tree, tree+n)-1;
    long long mid;

    while(1){
        mid = (low+high)/2;

        setSub(tree, sub, mid, n);

        if(getSum(sub, n) < m) high = mid - 1;
        else{
            setSub(tree, sub, mid+1, n);
            if(getSum(sub, n) < m) break;
            else low = mid + 1;
        }
    }

    cout << mid;
}