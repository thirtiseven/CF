#include <iostream>
#include <set>
#include <vector>

const int maxn = 1e5+7;
const int up = 4e6;

using ll = long long;

ll x[maxn];
unsigned n;
std::set<ll> p;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (ll i = 1; i <= up; i++) {
		p.insert(i*i);
	}
	for (unsigned i = 1; i <= n/2; i++) {
		std::cin >> x[i*2];
	}
	ll now = 0;
	ll cnt = 0;
	while (!p.count(cnt*cnt+x[2])) {
		cnt++;
		if (cnt > up) {
			std::cout << "No\n";
			exit(0);
		}
	}
	cnt--;
	x[1] = cnt*cnt;
	now = x[1];
	now += x[2];
	for (int i = 3; i <= n; i++) {
		if (i%2==1) {
			while (!p.count(now+cnt*cnt)) {
				cnt++;
				if (cnt > up) {
					std::cout << "No\n";
					exit(0);
				}
			}
			x[i] = (cnt-1LL)*(cnt-1LL);
		} else {
			if (!p.count(now+x[i])) {
				std::cout << "No\n";
				exit(0);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (x[i] > 1e13) {
			std::cout << "No\n";
			exit(0);
		}
	}
	for (int i = 1; i <= n; i++) {
		std::cout << x[i] << ' ';
	}
} 