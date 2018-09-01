#include <iostream>

using ll = long long;

int main(int argc, char *argv[]){
	ll n, q;
	std::cin >> n >> q;
	while (q--) {
		ll x, y, ans = 0;
		std::cin >> x >> y;
		x--, y--;
		ans = ((x * n + y)/2) + 1;
		if ((x+y)%2==1) {
			ans += ((n * n) + 1) /2;
		}
		std::cout << ans << '\n';
	}
}