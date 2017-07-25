#include <iostream>
#include <algorithm>

#define ll long long

int main(int argc, char *argv[]) {  
	ll a, b;
	std::cin >> a >> b;
	ll c = std::min(a, b);
	ll ans = 1;
	for(int i = 1; i <= c; i++) {
		ans *= i;
	}
	std::cout << ans << std::endl;
	return 0;
}