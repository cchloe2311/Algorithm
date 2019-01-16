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

int main(){
    int n, m;
    cin >> n >> m;

    int *tree =  new int[n];
    int *sub = new int[n];
    memset(sub, 0, sizeof(int)*n);

    for(int i=0; i<n; i++) cin >> tree[i];

    int h = *max_element(tree, tree+n);

    while(getSum(sub, n) < m){
        h--;
        for(int i=0; i<n; i++) {
            int tempSum = tree[i] - h;
            if(tempSum > 0) sub[i] = tree[i] - h;
        }
    }



    cout << h;
}