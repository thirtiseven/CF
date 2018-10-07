#include <iostream>
#include <queue>

using ll = long long;

std::priority_queue<ll> a, b;

int main(int argc, char *argv[]) {  
	ll n, l, r;
	ll ans = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> l >> r;
		a.push(l);
		b.push(r);
	}
	for (int i = 0; i < n; i++) {
		ans += std::max(a.top(), b.top());
		a.pop();
		b.pop();
	}
	std::cout << ans+n << '\n';
}