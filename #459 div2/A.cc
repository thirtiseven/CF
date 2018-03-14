#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) {  
	int f[2000];
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i < 1009; i++) {
		f[i] = f[i-1] + f[i-2];
	}
	int n[1009];
	memset(n, 0, sizeof(n));
	for (int i = 1; f[i] <= 1000; i++) {
		n[f[i]] = 1;
	}
	int nn;
	std::cin >> nn;
	for (int i = 1; i <= nn; i++) {
		std::cout << (n[i]?'O':'o');
	}
	std::cout << std::endl;
	return 0;
}