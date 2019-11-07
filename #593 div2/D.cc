#include <iostream>
#include <set>

const int maxn = 1e5+7;
using ll = long long;

std::set<ll> x[maxn];
std::set<ll> y[maxn];

ll n, m, k;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	ll u, v;
	for (ll i = 0; i < k; i++) {
		std::cin >> u >> v;
		x[u].insert(v);
		y[v].insert(u);
	}
	for (ll i = 1; i <= n; i++) {
		x[i].insert(0);
		x[i].insert(m+1);
	}
	for (ll i = 1; i <= m; i++) {
		y[i].insert(0);
		y[i].insert(n+1);
	}
	ll cur = 1;
	ll up = 0, down = n+1, left = 0, right = m+1;
	ll i = 1, j = 1, dir = 1, newi, newj; 
	ll add = 1;
	if (n*m-k == 1) {
		std::cout << "Yes\n";
		exit(0);
	}
	while (add > 0 || cur == 1) {
		if (dir == 1) {
			auto it = x[i].upper_bound(j);
//			std::cerr << *it << ' ';
			newj = std::min(right, *it)-1;
			dir = 2;
			add = newj-j;
			cur += add;
			j = newj;
			right = j+1;
			up++;
		} else if (dir == 2) {
			auto it = y[j].upper_bound(i);
//			std::cerr << *it << ' ';
			newi = std::min(down, *it)-1;
			dir = 3;
			add = newi-i;
			cur += add;
			i = newi;
			down = i+1;
			right--;
		} else if (dir == 3) {
			auto it = x[i].lower_bound(j);
			it--;
//			std::cerr << *it << ' ';
			newj = std::max(left, *it)+1;
			dir = 4;
			add = j-newj;
			cur += add;
			j = newj;
			left = j-1;
			down--;
		} else if (dir == 4) {
			auto it = y[j].lower_bound(i);
			it--;
//			std::cerr << *it << ' ';
			newi = std::max(up, *it)+1;
			dir = 1;
			add = i-newi;
			cur += add;
			i = newi;
			up = i-1;
			left++;
		} 
//		std::cerr << i << ' ' << j << ' ' << add << ' ' << cur << ' ' << dir << '\n';
//		std::cerr << ' ' << up << ' ' << right << ' ' << down << ' ' << left << '\n';
	}
//	std::cerr << cur << '\n';
	if (cur == n*m-k) {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
	}
}