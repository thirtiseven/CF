#include <iostream>
#include <string>

using ll = long long;
const ll mod = 1e9+7;

ll cal(char c) {
	return (long long)(c-'0');
}

ll T;
std::string s, t;
ll x;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> x >> s;
		ll i = 1;
		for (; s.size() < x; i++) {
			if (s[i-1] > 49) {
				t = s.substr(i);			
				for (ll j = 1; j < cal(s[i-1]); j++) {
					s += t;
				}
			}
		}
		ll l = s.length(), y;
		for (;i <= x; i++) {
			l = (i+cal(s[i-1])*(l-i+mod))%mod;		
		}
		std::cout << l << '\n';
	}
}