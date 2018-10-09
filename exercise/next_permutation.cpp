//
// Created by 최서정 on 2018. 10. 10..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int realValue[4] = {3, 1, 1, 1};

    vector<int> v1{0, 1, 2, 3};
    vector<int> v2{3, 1, 1, 1};
    vector<vector<int>> been;
    // 정렬되어 있어야 함
    do{
        vector<int> temp;
        for(auto it = v1.begin(); it != v1.end(); ++it) temp.push_back(realValue[*it]);
        if(find(been.begin(), been.end(), temp) == been.end()){
            been.push_back(temp);
            for(int i=0; i<temp.size(); i++) cout << temp[i] << " ";
            cout << endl;
        }
    }while(next_permutation(v1.begin(), v1.end()));

    cout << endl;

    do{
        for(auto it = v2.begin(); it != v2.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }while(next_permutation(v2.begin(), v2.end()));
}