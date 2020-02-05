#include <iostream>
#include <cstring>

const int maxn = 100000;
int flag[maxn], primes[maxn], totPrimes;

void euler_sieve(int n) {
	totPrimes = 0;
	memset(flag, 0, sizeof(flag));
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			primes[totPrimes++] = i;
		}
		for (int j = 0; i * primes[j] <= n; j++) {
			flag[i * primes[j]] = 1;
			if (i % primes[j] == 0)
			break;
		}
	}
}

int r, c;

int main(int argc, char *argv[]) {  
//	euler_sieve(99999);
	int cnt = 0;
	std::cin >> r >> c;
	if (r < 2 && c < 2) {
		std::cout << "0\n";
		exit(0);
	} else if (c == 1) {
		for (int i = 0; i < r; i++) {
			std::cout << i+2 << '\n';
		}
		exit(0);
	}
//	while (primes[cnt] <= r+c) {
//		cnt++;
//	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			std::cout << i*(r+c+1-j) << " \n"[j==c];
		}
	}
}