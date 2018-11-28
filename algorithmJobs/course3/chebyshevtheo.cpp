//#include <iostream>
//#include <vector>
//#include <string.h>
//using namespace std;
//
//int main(){
//    vector<int> input;
//    int temp, index = 0, max = 0;
//    cin >> temp;
//    input.push_back(temp);
//    while(input[index++] != 0){
//        if(temp > max) max = temp;
//        cin >> temp;
//        input.push_back(temp);
//    }
//
//    int *arr = new int[2*max+1];
//    memset(arr, 0, sizeof(int)*(2*max+1));
//
//    for(int i=2; i<=2*max+1; i++){
//        if(arr[i] != 0) continue;
//        for(int j=2*i; j<=2*max+1; j+=i) arr[j] = 1;
//    }
//
//    for(int i=0; i<input.size()-1; i++){
//        int result =0;
//        for(int j=input[i]+1; j<=2*input[i]; j++){
//            if(arr[j] == 0) result++;
//        }
//        cout << result<< endl;
//    }
//}