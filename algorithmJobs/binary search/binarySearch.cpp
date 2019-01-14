#include <iostream>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    int *num = new int[n];
    int *question = new int[q];

    for(int i=0; i<n; i++) cin >> num[i];
    for(int i=0; i<q; i++) cin >> question[i];

    for(int i=0; i<q; i++){
        int low = 0, high = n-1;
        int mid;

        while(1){
            mid = (low + high) / 2;
            if(low > high){
                cout << "NO"<< endl;
                break;
            }

            if(num[mid] == question[i]){
                cout << "YES"<< endl;
                break;
            }
            else if(num[mid] > question[i]) high = mid-1;
            else low = mid+1;
        }
    }
}