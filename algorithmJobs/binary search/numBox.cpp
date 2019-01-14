#include <iostream>
#include <list>
using namespace std;

void findPosition(list<int> &l, int input){
    list<int>::iterator iter;
    int check =0;
    for(iter= l.begin(); iter != l.end(); ++iter){
        if(*iter >= input){
            l.insert(iter, input);
            check = 1;
            break;
        }
    }

    if(check == 0) l.push_back(input);
}

bool isInList( int *box, int input, int size){
    int low = 0, high = size-1;
    int mid;

    while(low <= high){
        mid = (low + high) / 2;

        if(box[mid] == input) return true;
        else if(box[mid] > input) high = mid-1;
        else low = mid+1;
    }

    return false;
}

int main(){
    int n, m;
    list<int> l;

    cin >> n;
    int *box = new int[n];
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;

        if(l.empty()) l.push_back(temp);
        else findPosition(l, temp);
    }

    int index = 0;
    for(list<int>::iterator iter = l.begin(); iter != l.end(); ++iter, index++) box[index] = *iter;

    cin >> m;
    int *question = new int[m];
    for(int i=0; i<m; i++){
        int temp;
        cin >> temp;

        if(isInList(box, temp, n)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}