#include <iostream>
#include <algorithm>
#include <set>

const int maxn = 200009;
std::set<int> aa;
std::multiset<int> aaa;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n, a[maxn];
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		aa.insert(a[i]);
		aaa.insert(a[i]);
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		ans += ((2*i+1-n) * a[i]);
	}
	std::cout << ans << '\n';
	long long cnt = 0;
	for(auto it: aa) {
		cnt+=(aaa.count(it)*aaa.count(it+1));
	}
	std::cout << cnt << '\n';
	cnt/=2;
	ans -= cnt;
	std::cout << ans << '\n';
	return 0;
}