#include <iostream>

using ll = long long;
ll T, n, m;

ll gao(ll x) {
	return (x*(x+1ll)/2ll);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m;
		ll x = n-m;
		if (x == 0) {
			std::cout << gao(n) << '\n';
			continue;
		}
		ll y = std::min(x, m+1);
		ll less = x/y;
		ll more = less+1;
		ll n2 = x%y;
		ll n1 = y-n2;
//		std::cout << less << ' ' << n1 << ' ' << more << ' ' << n2 << ' ' << gao(n) << ' ' << gao(less) << ' ' << gao(more) << '\n';
		std::cout << gao(n)-n1*gao(less)-n2*gao(more) << '\n';
	}
}