#include <iostream>
#include <algorithm>
#include <map>
#include <set>

const int maxn = 2e5+7;

int n, m, k[maxn], kk[maxn];
std::map<int, std::set<int>> dt;
int sumk = 0;

bool check(int x) {
	for (int i = 0; i < maxn; i++) {
		kk[i] = k[i];
	}
	int now = 0;
	int cur = x;
	for (int i = x; i > 0; i--) {
		cur = std::min(cur, i);
		for (auto it: dt[i]) {
			if (kk[it] > 0) {
				int pur = std::min(kk[it], cur);
//				std::cout << "day " << i << " spent " << pur << " on " << it << "\n";
				cur -= pur;
				kk[it] -= pur;
				now += pur;
			}
		}
	}
	if (x-now >= (sumk-now)*2) {
//		std::cout << cur << " " << now << ' ';
//		std::cout << x << " yes\n";
		return 1;
	}
//	std::cout << x << " no\n";
	return 0;
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> k[i];
		sumk += k[i];
	}
	int dd, tt;
	for (int i = 1; i <= m; i++) {
		std::cin >> dd >> tt;
		dt[dd].insert(tt);
	}
	int l = sumk, r = sumk*2, mid;
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