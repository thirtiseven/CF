#include <iostream>

#define ll long long

int main(int argc, char *argv[]) {  
	ll k, p;
	std::cin >> k >> p;
	int ans = 0;
	for(ll i = 1; i <= k; i++) {
		ll temp = i, miao = i;
		while(miao) {
			temp = temp*10+miao%10;
			miao/=10;
		}
		//std::cout << temp << '\n';
		ans = (ans + temp) % p;
	}
	std::cout << ans << '\n';
	return 0;
}