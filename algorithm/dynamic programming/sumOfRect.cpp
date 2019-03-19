#include <iostream>
using namespace std;

int getSum(int **rect, int a, int b, int c, int d){
    int sum = 0;

    for(int i=a; i<=c; i++)
        for(int j=b; j<=d; j++){
            sum +=rect[i][j];
        }

    return sum;
}

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    int **rect = new int*[n];
    for(int i=0; i<n; i++) rect[i] = new int[m];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> rect[i][j];

    int *output = new int[q];
    for(int i=0; i<q; i++){
        int a, b, c, d;
        cin >> a >> b >> c>> d;

        output[i] = getSum(rect, a, b, c, d);
    }

    for(int i=0; i<q; i++) cout << output[i] << endl;
}