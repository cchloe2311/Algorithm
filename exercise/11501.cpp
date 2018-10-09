//
// Created by 최서정 on 2018. 10. 4..
//

#include <iostream>
using namespace std;

void setMaxValue(int *maxValue, int *value, int numOfDay){
    int max = value[numOfDay];
    for(int i = numOfDay-1; i>0; i--){
        if(max < value[i+1]) max = value[i+1];
        maxValue[i] = max;
    }
}

long long getSumOfMargin(int *maxValue, int *value, int numOfDay){
    long long sum = 0;
    for(int i=1; i<numOfDay; i++)
        if(maxValue[i]-value[i] > 0) sum+=maxValue[i]-value[i];
    return sum;
}

int main(){
    int testCase;
    cin >> testCase;
    cin.ignore();

    long long *result = new long long[testCase];
    result[0] = 1;
    for(int i=0; i<testCase; i++){
        int numOfDay;
        cin >> numOfDay;
        int *value = new int[numOfDay+1];
        int *maxValue = new int[numOfDay];

        for(int i=1; i<=numOfDay; i++) cin >> value[i];
        setMaxValue(maxValue, value, numOfDay);

        result[i] = getSumOfMargin(maxValue, value, numOfDay);
    }

    for(int i=0; i<testCase; i++)
        cout << result[i]<< endl;
}