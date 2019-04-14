#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

const int maxn = 100000+7;

using ll = long long;

ll n, q, l, r;
ll s[maxn];
std::set<ll> ss;
std::vector<ll> c;
ll que[maxn];
std::vector<ll> anss;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
		ss.insert(s[i]);
	}
	int cnt = 0;
	n = ss.size();
	for (auto it: ss) {
		s[cnt] = it;
		cnt++;
	}
	c.push_back(0);
	for (int i = 1; i < n; i++) {
		c.push_back(s[i]-s[i-1]);
	}
	std::sort(c.begin(), c.end());
	que[0] = 0;
	for (int i = 1; i < c.size(); i++) {
		que[i] = que[i-1] + (n-i+1) * (c[i]-c[i-1]);
	}
	std::cin >> q;
	while (q--) {
		std::cin >> l >> r;
		ll len = r-l+1;
		int left = 0, right = c.size()-1, mid;
		while (left < right) {
			mid = (left+right)/2;
			if (c[mid] < len) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		left--;
		ll ans = que[left] + (n-left)*(len-c[left]);
		anss.push_back(ans);
	}
	for (auto it: anss) {
		std::cout << it << " ";
	}
}