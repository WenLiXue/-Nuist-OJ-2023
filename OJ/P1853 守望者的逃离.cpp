#include<iostream>
using namespace std;
int main() {
	int m, s, t, a = 0, b = 0;
	cin >> m >> s >> t;
	for (int i = 1; i <= t; i++) {
		a += 17;
		if (m >= 10) {
			m -= 10;
			b += 60;
		}
		else m += 4;
		a = max(a, b);
		if (a >= s) {
			cout << "Yes" << endl << i;
			return 0;
		}
	}
	cout << "No" << endl << a;
	return 0;
}
