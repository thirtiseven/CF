#include <iostream>
#include <algorithm>
#include <set>

int n, m, q, x, y;
int ans = 0;
std::set<int> st[2001];
int cnt = 0;

void gao(int x, int y) {
	int label1 = -1, label2 = -1, len1, len2;
	if (x == 0 && y == n-1) {
		label1 = 0;
		len1 = 1;
		return;
	} else if (x == m-1 && y == 0) {
		label1 = cnt - 1;
		len1 = 1;
		return;
	}
	int temp = std::min(x, y);
	x -= temp;
	y -= temp;
	if (y) {
		label1 = n-1-y;
		len1 = 2*temp;
		label2 = n-1-y-1;
		len2 = 2*temp+1;
	} else {
		label1 = x+(n-1);
		len1 = 2*temp+1;
		label2 = x+(n-1)+1;
		len2 = 2*temp;
	}
	if (st[label1].count(len1) == 0) {
		int pre, nxt;
		auto it = st[label1].lower_bound(len1);
		it--;
		pre = *it;
		it = st[label1].upper_bound(len1);
		nxt = *it;
		ans -= (label1-pre) * (nxt-label1);
		std::cerr << pre << ' ' << nxt << '\n';
		st[label1].insert(len1);
	} else {
		int pre, nxt;
		auto it = st[label1].lower_bound(len1);
		it--;
		pre = *it;
		it = st[label1].upper_bound(len1);
		nxt = *it;
		ans += (label1-pre) * (nxt-label1);
		std::cerr << pre << ' ' << nxt << '\n';
		st[label1].erase(len1);
	}
	if (label2 != -1) {
		if (st[label2].count(len2) == 0) {
			int pre, nxt;
			auto it = st[label2].lower_bound(len2);
			it--;
			pre = *it;
			it = st[label2].upper_bound(len2);
			nxt = *it;
			std::cerr << pre << ' ' << nxt << '\n';
			ans -= (label2-pre) * (nxt-label2);
			st[label2].insert(len2);
		} else {
			int pre, nxt;
			auto it = st[label2].lower_bound(len2);
			it--;
			pre = *it;
			it = st[label2].upper_bound(len2);
			nxt = *it;
			std::cerr << pre << ' ' << nxt << '\n';
			ans += (label2-pre) * (nxt-label2);
			st[label2].erase(len2);
		}
	}
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m >> q;
	for (int i = 1; i < std::min(m, n); i++) {
		int len = i*2+1;
		st[cnt].insert(0);
		st[cnt].insert(len+1);
		ans += (len*(len+1)/2);
		cnt ++;
	}
	for (int i = std::min(m, n); i < std::max(m, n); i++) {
		int len = std::min(m, n)*2;
		st[cnt].insert(0);
		st[cnt].insert(len+1);
		ans += (len*(len+1)/2);
		cnt ++;
	}
	for (int i = std::max(m, n); i < m + n - 1; i++) {
		int temp = m + n - 1 - i;
		int len = temp * 2;
		st[cnt].insert(0);
		st[cnt].insert(len+1);
		ans += (len*(len+1)/2);
		cnt ++;
	}
	std::cout << ans << '\n';
	for (int i = 0; i < q; i++) {
		std::cin >> x >> y;
		gao(x, y);
		std::cout << ans << '\n';
	}
}