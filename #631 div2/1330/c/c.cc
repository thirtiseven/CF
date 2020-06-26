#include <iostream>
#include <algorithm>

using ll = long long;
const ll maxn = 100000+7;
ll n, m, l[maxn], shu[maxn];


int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m;
	ll sum = 0, maxx = 0;
	for (ll i = 0; i < m; i++) {
		std::cin >> l[i];
		sum += l[i];
		maxx = std::max(maxx, i+l[i]);
	}
	if (maxx > n || sum < n) {
		std::cout << "-1\n";
		exit(0);
	}
	shu[m] = 0;
	for (ll i = m-1; i >= 0; i--) {
		shu[i] = shu[i+1] + l[i];
	}
	ll take = 0, now = 1;
	for (ll i = 0; i < m; i++) {
		std::cout << now << ' ';
		take = std::max(take, now+l[i]-1);
		if (shu[i+1] + take >= n && shu[i+1] + now <= n) {
			now = n-shu[i+1]+1;
		} else {
			now++;
		}
	}
}