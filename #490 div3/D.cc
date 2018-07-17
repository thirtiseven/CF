#include <set>
#include <algorithm>
#include <iostream>

const int maxn = 2e5+7;
using ll = long long int;

ll n, m, a[maxn], c[maxn], ans;
std::set<int> s;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);  
	std::cin >> n >> m;
	for (int i = 0; i < m; i++){
		s.insert(i);
	}
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		int d = a[i]%m, x;
		if (d > *s.rbegin()) x = *s.begin();
		else x = *s.lower_bound(d);
		if (++c[x] == n/m) s.erase(x);
		ans += (x+m-d)%m;
		a[i] += (x+m-d)%m;
	}
	std::cout << ans << '\n';
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
}