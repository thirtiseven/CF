#include <iostream>

using ll = long long;

ll t, a, k;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> a >> k;
		ll x = k*k;
		if (a >= x && (a-x)%2==0) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}