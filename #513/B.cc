#include <iostream>
#include <string>

using ll = long long;

int main(int argc, char *argv[]) {  
	ll n;
	std::cin >> n;
	ll nn = 9, cnt = 0;
	while (nn <= n) {
		nn = nn*10+9;
		cnt++;
	}
	nn = (nn-9)/10;
	ll ans = cnt*9;
	n -= nn;
	while (n) {
		ans += n%10;
		n/=10;
	}
	std::cout << ans;
}