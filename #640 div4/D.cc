#include <iostream>

const int maxn = 1002;

int t, n, a[maxn], alice, bob;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		alice = bob = 0;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		int l = 0, r = n-1;
		int rnd = 0, cur = 0;
		while (l <= r) {
			int now = 0;
			if (rnd % 2 == 0) {
				while (now <= cur && l <= r) {
					now += a[l];
					l++;
				}
				alice += now;
			} else {
				while (now <= cur && l <= r) {
					now += a[r];
					r--;
				}
				bob += now;
			}
			cur = now;
			rnd++;
//			std::cout << rnd << ": " << alice << ' ' << bob << ' ' << now << ' ' << l << ' ' << r <<  '\n';
		}
		std::cout << rnd << ' ' << alice << ' ' << bob << '\n';
	}
}