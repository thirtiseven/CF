#include <iostream>

using ll = long long;

ll n, m;

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	if (m%n!=0) {
		std::cout << "-1\n";
		exit(0);
	}
	ll res = m/n;
	ll ans = 0;
	while (res % 2 == 0) {
		res /= 2;
		ans++;
	}
	while (res % 3 == 0) {
		res /= 3;
		ans++;
	}
	if (res != 1) {
		std::cout << "-1\n";
	} else {
		std::cout << ans << '\n';
	}
}