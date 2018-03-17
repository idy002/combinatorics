#include <iostream>
#include <iomanip>
using namespace std;

const int N = 5000 + 10;

int comb[N][N];

void init(int n) {
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= i; j++) {
			if(j == 0 || j == i)
				comb[i][j] = 1;
			else
				comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) & 1;
		}
	}
}
int count(int i) {
	int cnt = 0;
	for(int j = 0; j <= i; j++)
		cnt += comb[i][j];
	return cnt;
}
bool property0(int n) {
	for(int i = 0; i <= n; i++) {
		int c = count(i);
		if(c != (c & -c)) 
			return false;
	}
	return true;
}
bool property1(int n) {
	for(int i = 0; i + 4 < n; i+=4) {
		int c[4];
		for(int j = 0; j < 4; j++) 
			c[j] = count(i+j);
		if(c[0]<<1 != c[1] || c[0]<<1 != c[2] || c[0]<<2 != c[3]) 
			return false;
	}
	return true;
}
int constants[4] = { 1, 2, 2, 4 };
int f(int n) {
	if(n == 0) return 1;
	return f(n / 4) * constants[n % 4];
}
bool property2(int n) {
	for(int i = 0; i <= n; i++) {
		if(count(i) != f(i)) return false;
	}
	return true;
}
int main() {
	int n = 5000;
	init(n);
	cout << "property 0 " << (property0(n) ? "holds" : "does not hold") << endl;
	cout << "property 1 " << (property1(n) ? "holds" : "does not hold") << endl;
	cout << "property 2 " << (property2(n) ? "holds" : "does not hold") << endl;
	cout << setw(2) << endl;
	while(1) {
		int top, bottom;
		cin >> top >> bottom;
		for(int i = top; i <= bottom; i++) {
			for(int j = 0; j <= i; j++) {
				cout << comb[i][j] << " ";
			}
			cout << endl;
		}
	/*
		if(0 <= top && top <= bottom && bottom <= n) {
			for(int i = top; i <= bottom; i++) 
				cout << i << ": " << count(i) << " " << f(i) << endl;
		} else {
			cout << "out of range [0,5000]" << endl;
		}
	*/
	}
}

