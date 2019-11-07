#include <iostream>

using ll = unsigned long long;

ll n, p, w, d;

int main(int argc, char *argv[]) {  
	std::cin >> n >> p >> w >> d;
	if ((p/d > n || (p/d == n && p%d!=0)) && (p/w > n || (p/w == n && p%w!=0))) {
		std::cout << "-1\n";
		exit(0);
	}
	if (p == 0) {
		std::cout << "0 0 " << n << '\n';
		exit(0);
	}
	if (w > d) {
		for (ll i = p/w; i > 0; i--) {
			if ((p-w*i)%d == 0) {
				if (i + (p-w*i)/d <= n && i + (p-w*i)/d >= 0) {
					std::cout << i << ' ' << (p-w*i)%d << ' ' << n-i-(p-w*i)%d << '\n';
					exit(0);
				} else {
					std::cout << "-1\n";
					exit(0);
				}
			}
		}
	} else {
		for (ll i = 0; i <= std::min(n, p/w); i++) {
			if ((p-w*i)%d == 0) {
				if (i + (p-w*i)/d <= n &&  i + (p-w*i)/d >= 0) {
					std::cout << i << ' ' << (p-w*i)%d << ' ' << n-i-(p-w*i)%d << '\n';
					exit(0);
				} else {
					std::cout << "-1\n";
					exit(0);
				}
			}
		}
		
	}
	std::cout << "-1\n";
	exit(0);
}