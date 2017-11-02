#include <iostream>
#include <algorithm>

#define ll long long

int main(int argc, char *argv[]) {  
	ll a, b, f, k;
	std::cin >> a >> b >> f >> k;
	ll fj = f * 2, sj = 2 * (a - f), fa = a - f;
	bool yes = 1;
	int ans = 0;
	if(fj > b || sj > b) {
		yes = 0;
	} else if(2 * a > b) {
		ans = k;
		if(fa + a <= b) {
			ans--;
			if(k % 2 == 0 && k != 2) {
				ans--;
			}
		}
		if(f + a <= b && k % 2 == 1) {
			ans--;
		}
	} else {
		ans = k/(b/(2*a))/2 - 1;
		if(b%(2*a) < f) {
			ans++;
		}
		if(b%(2*a) < fa && k % 2 == 1 && k != b/(2*a)*2+1) {
			ans++;
		}
		if(k == b/(2*a)*2+1) {
			if(b%(2*a) > a) {
				ans = 1;
			} else {
				ans = 2;
			}
		}
	}
	if(k * a <= b) {
		ans = 0;
	}
	if(yes) {
		std::cout << ans << std::endl;
	} else {
		std::cout << "-1\n";
	}
	//std::cout << ans << std::endl;
	return 0;
}