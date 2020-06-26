#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
const int maxn = 2e5+7;

ll n, k, a[maxn];
std::vector<ll> v;

bool check(ll x) {
//	v.clear();
	ll siz = 0;
	for (int i = 0; i < n; i++) {
		if (siz%2==0) {
			if (a[i] <= x) {
				siz++;
			}
		} else {
			siz++;
		}
	}
	if (siz >= k) {
		return true;
	}
	siz = 0;
	for (int i = 0; i < n; i++) {
		if (siz%2==1) {
			if (a[i] <= x) {
				siz++;
			}
		} else {
			siz++;
		}
	}
	if (siz >= k) {
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	ll l = 1, r = 1000000000, mid;
	while (l <= r) {
		mid = (l+r)/2;
		if (check(mid)) {
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
	std::cout << l << '\n';
}