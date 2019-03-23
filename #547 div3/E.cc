#include <iostream>
#include <algorithm>

using ll = long long;

const int maxn = 2e5+7;
ll d[maxn];
ll H;
ll n;
ll sum = 0;
ll maxx = 1e6+7;

int main(int argc, char *argv[]) {  
	std::cin >> H >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> d[i];
		sum += d[i];
		maxx = std::min(sum, maxx);
	}
	maxx = -maxx;
	if (sum >= 0 && maxx < H) {
		std::cout << "-1\n";
		exit(0);
	}
	sum = -sum;
	ll ans = 0;
	if (maxx < H) {
		ans = (H-maxx)/sum*n;
		H = (H-maxx)%sum+maxx;
	}
	while (H > 0) {
		for (int i = 0; i < n; i++) {
			H += d[i];
			ans ++;
			if (H <= 0) {
				break;
			}
		}
	}
	std::cout << ans << '\n';
}