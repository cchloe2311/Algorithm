#include <iostream>
using namespace std;

class Count{
public:
    int seq[2];
    Count() {
        this->seq[0] = 0;
        this->seq[1] = 0;
    }
};

int main(){
    int n;
    cin >> n;

    int *cards = new int[n+1];
    for(int i=1; i<=n; i++) cin >> cards[i]; // 자연수 점수

    Count *count = new Count[n];
    count[0].seq[0] = count[0].seq[1] = 0;

    count[1].seq[0] = cards[1];
    count[1].seq[1] = 0;


    // 두개를 연달아 갖지 않는 경우도 고래해야하나?
    for(int i=2; i<=n; i++){
        count[i].seq[0] = count[i-2].seq[0] > count[i-2].seq[1] ? count[i-2].seq[0] : count[i-2].seq[1];
        count[i].seq[0] += cards[i];
        count[i].seq[1] = count[i-1].seq[0] + cards[i];
    }

    int max = count[n].seq[0] > count[n].seq[1] ? count[n].seq[0] : count[n].seq[1];
    if(max < count[n-1].seq[1]) max = count[n-1].seq[1];

    cout << max;
}