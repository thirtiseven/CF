#include <iostream>
#include <algorithm>
#include <string>

using ll = long long;

ll a[123456];

int main(int argc, char *argv[]) {  
	ll n;
	std::cin >> n;
	for (ll i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	char b[123456];
	std::cin >> b;
	ll l = -1e9, r = 1e9;
	for (ll i = 4; i < n; i++) {
		if (b[i] == '0' && b[i-1] == '1') {
			r = std::min(r, a[i]);
			r = std::min(r, a[i-1]);
			r = std::min(r, a[i-2]);
			r = std::min(r, a[i-3]);
			r = std::min(r, a[i-4]);
		} else if (b[i] == '1' && b[i-1] == '0') {
			l = std::max(l, a[i]);
			l = std::max(l, a[i-1]);
			l = std::max(l, a[i-2]);
			l = std::max(l, a[i-3]);
			l = std::max(l, a[i-4]);
		}
	}
	std::cout << l+1 << " " << r-1;
}