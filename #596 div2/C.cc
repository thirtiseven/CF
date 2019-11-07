#include <iostream>

using ll = long long;

int main(int argc, char *argv[]) {  
	ll n, p;
	std::cin >> n >> p;
	ll cnt = 0;
	while (n) {
		n -= p;
		if (n < 1) {
			break;
		}
		cnt++;
		if (cnt >= __builtin_popcount(n) && cnt <= n) {
			std::cout << cnt << '\n';
			exit(0);
		}
	}
	std::cout << "-1\n";
}