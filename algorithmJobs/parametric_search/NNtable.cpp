#include <iostream>
#include <utility>
using namespace std;

pair<long long, long long> countOnTable(int n, int mid){
    long long smaller = 0, equal = 0;
    if(mid <= n) {
        equal++;
        smaller += mid-1;
    }
    else smaller += n;
    for(int i=2; i<=n; i++){
        if(mid % i == 0) {
            equal++;
            smaller += (long long) mid/i-1;
        }
        else smaller += (long long) mid/i;
    }

    return {smaller, equal};
}

int main(){
    int n, k;
    cin >> n >> k;

    int low = 1;
    int high = n*n;
    int mid;

    while(1){
        mid = (low+high)/2;

        pair<long long, long long> count = countOnTable(n, mid);

        if(count.first < k && k <= count.first+count.second) break;
        else if (count.first+count.second < k) low = mid+1;
        else high = mid-1;
    }

    cout << mid;
}