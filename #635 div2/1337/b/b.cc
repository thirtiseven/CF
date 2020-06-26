#include <iostream>

using ll = long long;
ll t, x, n, m;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> x >> n >> m;
		bool yes = 1;
		while (x >= 20 && n) {
			x = x/2+10;
			n--;
		}
		while (m) {
			x -= 10;
			m--;
		}
		std::cout << (x<=0?"YES\n":"NO\n");
	}
}