#include <iostream>
#include <string>
using namespace std;

#define DIGITS 3

bool isGoodSeq(string seq) {
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
			if (n != 1) {
                if (makeSeq(seq + char(48 + i), n - 1)) return true;
            }
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

	makeSeq("", n);
}