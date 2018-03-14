#include <iostream>

int perfect[10009];

int main(int argc, char *argv[]) {  
	int a = 19;
	int cnt = 0;
	while (cnt < 10000) {
		int tot = 0;
		int t = a;
		while (t) {
			tot += t%10;
			t /= 10;
		}
		if(tot == 10) {
			perfect[cnt] = a;
			cnt++;
		}
		a++;
	}
	int nn;
	std::cin >> nn;
	std::cout << perfect[nn-1];
}