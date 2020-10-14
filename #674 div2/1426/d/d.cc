#include <iostream>
#include <algorithm>
#include <set>

const int maxn = 200007;
using ll = long long;

ll n, a[maxn];
std::set<ll> s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	s.insert(0);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	ll sum = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (s.count(sum) == 1) {
			ans++;
			s.clear();
			sum = a[i];
			s.insert(0);
		}
		s.insert(sum);
	}
	std::cout << ans << '\n';
}