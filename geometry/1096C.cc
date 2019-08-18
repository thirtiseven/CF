#include <iostream>

using ll = int;

ll gcd(ll a, ll b) { 
	ll t;
	while(b != 0) { 
		t=a%b;
		a=b;
		b=t; 
	}
	return a; 
}

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		int ang;
		std::cin >> ang;
		if (ang == 179) {
			std::cout << "360\n";
			continue;
		} else if (ang == 90) {
			std::cout << "4\n";
			continue;
		}
		int ans = 180/gcd(180, ang);
		if (ang > 90 && (180-ang)/gcd(180, ang)==1) {
			ans*=2;
		}
		std::cout << ans << '\n';
	}
}