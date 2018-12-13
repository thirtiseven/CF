#include <iostream>

using ll = long long;

int main(int argc, char *argv[]) {  
	ll t, a, b, s, c;
	std::cin >> t;
	while (t--) {
		std::cin >> s >> a >> b >> c;	
		ll num = s/c;
		ll addd = num/a*b;
		std::cout << num+addd << '\n';
	}	
}