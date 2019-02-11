#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    int **score = new int*[n+1];
    for(int i=0; i<=n; i++) score[i] = new int[3];

    score[0][0] = score[0][1] = score[0][2] = 0;
    for(int i=1; i<=n; i++) cin >> score[i][0] >> score[i][1] >> score[i][2];

    for(int i=1; i<=n; i++){
        score[i][0] += max(score[i-1][1], score[i-1][2]);
        score[i][1] += max(score[i-1][0], score[i-1][2]);
        score[i][2] += max(score[i-1][0], score[i-1][1]);
    }

    int maxValue = 0;
    for(int i=0; i<3; i++)
        if(maxValue < score[n][i]) maxValue = score[n][i];

    cout << maxValue;
}