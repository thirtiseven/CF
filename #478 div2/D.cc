#include <iostream>
#include <map>
#include <utility>

using ll = long long;

int main(int argc, char *argv[]) {
	int n;
	std::cin >> n;
	ll a, b;
	std::cin >> a >> b;
	std::map<ll,ll> vis;
	std::map<std::pair<int,int>,int> sim;
	ll ans = 0;
	for(int i=1; i<=n; i++) {
		int x, vx, vy;
		std::cin >> x >> vx >> vy;
		ans += vis[a*vx-vy] - sim[{vx,vy}];
		vis[a*vx-vy]++;
		sim[{vx,vy}]++;
	}
	std::cout << 2*ans << std::endl;
}