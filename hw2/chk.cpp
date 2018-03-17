#include <bits/stdc++.h>
using namespace std;

set<int> A, B;

int main() {
	A.insert(0);
	for(int n  = 1; n <= 1e5; n++) {
		int ca = 0, cb = 0;
		for(int i = 1; i < n - i; i++) {
			if(A.count(i) && A.count(n - i)) ca++;
			if(B.count(i) && B.count(n - i)) cb++;
		}
		if(ca == cb)
			B.insert(n);
		else if(ca + 1 == cb)
			A.insert(n);
		else {
			fprintf(stderr, "There does not exist such set A and B\n");
			return 0;
		}
		fprintf(stderr, "%d %d %d\n", n, ca, cb);
	}
	/*
	for(auto n : A)
		fprintf(stderr, "%d ", n % 4);
	fprintf(stderr, "\n");
	for(auto n : B)
		fprintf(stderr, "%d ", n % 4);
	fprintf(stderr, "\n");
	*/
}

/*
int type[12] = {
	0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1
};


int main() {
	for(int n = 1; ; n++) {
		int cnt = 0;
		for(int i = 0; i < n - i; i++) {
			if(type[i % 12] == type[(n - i) % 12]) {
				if(type[i % 12] == 0) 
					cnt++;
				else 
					cnt--;
			}
		}
		if(cnt != 0) {
			fprintf(stderr, "%d not satisfies\n", n);
			for(int i = 0; i < n - i; i++)
				if(type[i % 12] == type[(n - i) % 12]) {
					fprintf(stderr, "%d %d %d\n", type[i % 12], i, n - i);
				}
			for(int i = 0; i < 12; i++)
				if(type[i]) 
					fprintf(stderr, "%d ", i);
			fprintf(stderr, "\n");
			for(int i = 0; i < 12; i++)
				if(!type[i]) 
					fprintf(stderr, "%d ", i);
			fprintf(stderr, "\n");
			return 0;
		} else
			fprintf(stderr, "%d satisfies\n", n);
	}
}
*/
