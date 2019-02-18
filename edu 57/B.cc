#include <iostream>
#include <string>

using ll = long long;
const ll mod = 998244353;

int main(int argc, char *argv[]) {  
	int n;
	std::string s;
	std::cin >> n >> s;
	ll l = 1, r = 1;
	for (int i = 0; i < n-1; i++) {
		if (s[i] == s[i+1]) l++;
		else break;
	}
	for (int i = n-1; i >= 1; i--) {
		if (s[i] == s[i-1]) r++;
		else break;
	}
//	std::cout << l << " " << r << '\n';
	if (l==n) {
		std::cout << (n*(n+1LL))/2ll%mod << '\n';
	} else {
		if (s[0] == s[n-1]) {
			std::cout << (l+1LL)*(r+1LL)%mod << '\n';
		} else {
			std::cout << (l+r+1LL)%mod << '\n';
		}
	}
}