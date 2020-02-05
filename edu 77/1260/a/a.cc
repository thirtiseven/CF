#include <iostream>

using ll = long long;

ll n, c, sum;
ll ans;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	while (n--) {
		ans = 0;
		std::cin >> c >> sum;
		ll x = sum/c, y = sum%c;
		ll z = c-y;
		ans += z*x*x+y*(x+1)*(x+1);
		std::cout << ans << '\n';
	}
}