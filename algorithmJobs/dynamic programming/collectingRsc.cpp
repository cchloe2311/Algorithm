#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int **resource = new int*[n];
    for(int i=0; i<n; i++) resource[i] = new int[m];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> resource[i][j];

    for(int i=1; i<n; i++){
        resource[i][0] += resource[i-1][0];
        for(int j=1; j<m; j++){
            resource[i][j] += max(resource[i][j-1], resource[i-1][j]);
        }
    }

    cout << resource[n-1][m-1];
}