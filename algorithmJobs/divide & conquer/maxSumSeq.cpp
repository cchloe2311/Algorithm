#include <iostream>
#include <vector>
using namespace std;

int findMaxSum(vector<int>::iterator begin, vector<int>::iterator end){
    int sum = 0, max = 0; // 아예 더하지 않는 경우

    for(begin; begin != end; ++begin){
        sum += *begin;
        if(sum > max) max = sum;
    }

    return max;
}

int main(){
    int n;
    cin >> n;

    vector<int> input(n);
    for(int i=0; i<n; i++) cin >> input[i];

    int max  = 0;
    for(vector<int>::iterator p = input.begin(); p != input.end(); ++p){
        int temp = findMaxSum(p, input.end());
        if(temp > max) max = temp;
    }

    cout << max;
}