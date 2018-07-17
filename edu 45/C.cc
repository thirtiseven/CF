#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <set>

using ll = long long int;
std::multiset<ll> ms;
std::string s;

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	ll n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> s;
		ll t = 0;
		int ok = 1;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				t++;
			} else {
				t--;
				if (t<0) {
					ok = 0;
					
				}
			}
		}
		if (!ok) {
			t = 0;
			ok = 1;
			for (int i = s.length()-1; i >= 0; i--) {
				if (s[i] == ')') {
					t++;
				} else {
					t--;
					if (t<0) {
						ok = 0;
						break;
					}
				}
			}
			if (ok) ms.insert(-t);
		} else ms.insert(t);
	}
	ll ans = 0;
	ll z = 2*ms.count(0);
	for (auto i: ms) {
		if (i == 0) {
			ans += z;
		} else {
			ans += ms.count(-i);
		}
	}
	std::cout << ans/2;
}