#include <iostream>
#define ll long long

int main(int argc, char *argv[]) {  
	ll a, b;
	std::cin >> a >> b;
	ll ans = 1;
	for(ll i = a + 1; i <= b; i++) {
		ans = (ans * i) % 10;
		//std::cout << ans << std::endl;
		if(ans == 0) {
			break;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}