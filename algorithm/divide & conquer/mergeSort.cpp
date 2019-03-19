#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> a, vector<int> b){
    vector<int> sortedV(a.size()+b.size());
    int index = 0;

    vector<int>::iterator pA = a.begin();
    vector<int>::iterator pB = b.begin();

    while(1){
        if(*pA <= *pB) {
            sortedV[index++] = *pA;
            pA++;
        }
        else{
            sortedV[index++] = *pB;
            pB++;
        }

        if(pA == a.end()){
            while(pB != b.end()){
                sortedV[index++] = *pB;
                pB++;
            }
            break;
        }
        else if(pB == b.end()){
            while(pA != a.end()){
                sortedV[index++] = *pA;
                pA++;
            }
            break;
        }
    }

    return sortedV;
}

void divide(int low, int high, vector<int> &v){
    int mid = (low+high)/2;

    if(low != mid) divide(low, mid, v);
    if(mid != high) divide(mid+1, high, v);

    if(low != high){
        vector<int> preV, postV;

        preV.resize((mid-low+1));
        copy(v.begin()+low, v.begin()+mid+1, preV.begin());
        postV.resize(high-mid);
        copy(v.begin()+mid+1, v.begin()+high+1, postV.begin());

        vector<int> sortedV = merge(preV, postV);
        copy(sortedV.begin(), sortedV.end(), v.begin()+low);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> input(n);
    for(int i=0; i<n; i++) cin >> input[i];

    divide(0, n-1, input);

    for(int i=0; i<n; i++) cout << input[i] << " ";
}