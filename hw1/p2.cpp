#include <iostream>
#include <bitset>
using namespace std;

const int N = 100 + 10;

bitset<16> a[17];

int main() {
	a[0][0] = 1;
	a[1][1] = 1;
	int n = 15;
	for(int i = 2; i <= n; i++)
		a[i] = a[i-2] ^ (a[i-1]<<1);
	for(int i = 0; i <= n; i++) 
		cout << "$A_{" << i << "} = " << a[i] << "$ \\\\" << endl;

}
