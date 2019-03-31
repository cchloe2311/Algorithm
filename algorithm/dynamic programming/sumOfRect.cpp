#include <iostream>
#include <string.h>
using namespace std;

int getSum(int **partSum, int a, int b, int c, int d){
    int sum = partSum[c + 1][d + 1];

    sum -= (partSum[c + 1][b] + partSum[a][d + 1]);
    sum += partSum[a][b];

    return sum;
}

void getPartSum(int **rect, int **partSum, int n, int m) {

    for (int i = 1; i <= n; i++) {
        int rowSum = 0;
        for (int j = 1; j <= m; j++) {
            rowSum += rect[i - 1][j - 1];

            partSum[i][j] = partSum[i - 1][j] + rowSum;
        }
    }
}

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    int **rect = new int*[n];
    int **partSum = new int*[n + 1];
    for(int i=0; i<n; i++) {
        rect[i] = new int[m];
        partSum[i] = new int[m + 1];
        memset(partSum[i], 0, sizeof(int) * (m + 1));
    }
    partSum[n] = new int[m + 1];
    memset(partSum[n], 0, sizeof(int) * (m + 1));


    for(int i=0; i<n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rect[i][j];
        }
    }

    getPartSum(rect, partSum, n, m);

//    for (int i = 0; i < n + 1; i++) {
//        for (int j = 0; j < m +1; j++) cout << partSum[i][j] << "\t";
//        cout << endl;
//    }

    int *output = new int[q];
    for(int i=0; i<q; i++){
        int a, b, c, d;
        cin >> a >> b >> c>> d;

        output[i] = getSum(partSum, a, b, c, d);
    }

    for(int i=0; i<q; i++) cout << output[i] << endl;
}