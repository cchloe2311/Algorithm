#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isInList(int *input, int temp, int size){
    int low = 0, high = size-1;
    int mid;

    while(low <= high){
        mid = (low + high) / 2;

        if(input[mid] == temp) return true;
        else if(input[mid] > temp) high = mid-1;
        else low = mid+1;
    }

    return false;
}

int main(){
    int n, m;

    cin >> n;

    int *input = new int[n];
    for(int i=0; i<n; i++) cin >> input[i];

    sort(input, input+n);

    cin >> m;
    int *question = new int[m];
    for(int i=0; i<m; i++){
        int temp;
        cin >> temp;

        if(isInList(input, temp, n)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}