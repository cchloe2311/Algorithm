#include <iostream>
#include <utility>
#include <string.h>
#include <algorithm>
using namespace std;

int getSum(int *sub, int n){
    int sum = 0;
    for(int i=0; i<n; i++) sum+=sub[i];
    return sum;
}

void setSub(int *tree, int *sub, int mid, int n){
    for(int i=0; i<n; i++) {
        int tempSum = tree[i] - mid;
        if(tempSum > 0) sub[i] = tree[i] - mid;
        else sub[i] = 0;
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    int *tree =  new int[n];
    int *sub = new int[n];
    //memset(sub, 0, sizeof(int)*n);

//    int tree[4];
//    int sub[4];

    for(int i=0; i<n; i++) cin >> tree[i];

    int low = 0;
    int high = *max_element(tree, tree+n);
    int mid;

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