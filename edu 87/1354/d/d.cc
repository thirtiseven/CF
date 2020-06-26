#include <iostream>
#include <algorithm>

const int maxn = 1e6+7;

int n, q, a, k, tree[maxn];

void add(int i, int x) {
	for(;i <= n; i += i & -i)
		tree[i] += x;
}

int sum(int i) {
	int ret = 0;
	for(; i; i -= i & -i) ret += tree[i];
	return ret;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		std::cin >> a;
		add(a, 1);
	}
	for (int i = 1; i <= q; i++) {
		std::cin >> k;
		if (k >= 1) {
			add(k, 1);
		} else {
			if (sum(n) >= -k) {
				int l = 1, r = n, mid;
				while (l <= r) {
					mid = (l+r)/2;
					if (sum(mid) >= -k) {
						r = mid-1;
					} else {
						l = mid+1;
					}
				}
				add(l, -1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (sum(i) > 0) {
			std::cout << i << '\n';
			exit(0);
		}
	}
	std::cout << "0\n";
}