#include <iostream>

using ll = long long;

int main(int argc, char *argv[]) {  
	ll n, k, a, b, x;
	std::cin >> n >> k >> a >> b;
	if (k == 1) {
		std::cout << (n-1)*a;
		return 0;
	}
	x = n;
	ll cost = 0;
	if (x % k != 0 && x > k) {
		cost += (x%k)*a;
		x -= (x%k);
	}
	while (x > 1) {
//		std::cout << x << ' ' << cost <<'\n';
		if (x < k) {
			cost += a*(x-1);
			break;
		}
		if ((x - x/k)*a > b) {
			x /= k;
			cost += b;
//			std::cout << x << ' ' << cost <<'\n';
			if (x % k != 0 && x > k) {
				cost += (x%k)*a;
				x -= (x%k);
			} else if (x < k) {
				cost += (x-1)*a;
				x = 1;
				break;
			}
		} else {
			cost += a*k;
			x-=k;
			if (x == 0) {
				x++;
				cost -= a;
				break;
			}
		}
//		std::cout << x << ' ' << cost <<"\n\n";
	}
	std::cout << cost;
}