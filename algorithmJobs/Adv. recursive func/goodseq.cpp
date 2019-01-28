#include <iostream>
#include <string>
using namespace std;

#define DIGITS 3

bool isGoodSeq(string seq) {
	// 이미 GoodSeq인 string에
	// 뒤에 새로운 숫자 하나가 붙은 상태

	// 좋지않은 시퀀스가 되는 케이스
	// ~123 => ~1233 // newseq와 가장 뒤에 거를 비교
	// ~121 => ~1212 // 뒤에서 두개랑 앞에 두개를 비교
	// ~12312 => ~123123 // 뒤에서 세개랑 앞에 세개를 비교

	for (int i = 1; i <= seq.size() / 2; i++) {
		// substr(position, size)
		string post = seq.substr(seq.size()-i, i);
		string pre = seq.substr(seq.size()-2*i, i);
		if (post == pre) return false;
	}
	return true;
}

bool makeSeq(string seq, int n) {
	for (int i = 1; i <= DIGITS; i++)
		if (isGoodSeq(seq + char(48+i))) {
			if (n != 0)
				if(makeSeq(seq + char(48 + i), n-1)) return true;
			else {
					cout << seq+char(48+i);
					return true;
			}
		}

	return false;
}

int main() {
	int n;
	cin >> n;

	// n자리의 3진수를 만드는 것과 같음
	makeSeq("", n);
}