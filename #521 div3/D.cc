#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

const int maxn = 2e5+7;

int cnt[maxn];
std::vector<int> v;
int n, k;

bool check(int m) {
	int cnt = 0;
	for (auto it: v) {
		cnt += it/m;
	}
	if (cnt >= k) {
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) {  
	std::fill(cnt, cnt+maxn, 0);
	std::cin >> n >> k;
	int t;
	for (int i = 0; i < n; i++) {
		std::cin >> t;
		cnt[t]++;
	}
	for (auto it: cnt) {
		if (it > 0) v.push_back(it);
	}
	int l = 1, r = n, m;
	while (l <= r) {
		m = (l+r)/2;
		if (check(m)) {
			l = m+1;
		} else {
			r = m-1;
		}
	}
	int tot = 0;
	l--;
	for (int i = 0; i < maxn; i++) {
		while (cnt[i] >= l && tot < k) {
			std::cout << i << ' ';
			cnt[i] -= l;
			tot++;
		}
	}
}