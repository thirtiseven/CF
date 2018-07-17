#include <iostream>
#include <set>
#include <map>

int main(int argc, char *argv[]) {  
	std::multiset<int> a;
	std::set<int> aa;
	std::map<int, int> m;
	int n, t;
	int ans = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> t;
		a.insert(t);
		aa.insert(t);
	}
	for (int it: aa) {
		m[a.count(it)]++;
		std::cout << a.count(it) << " " << m[a.count(it)] << '\n';
	}
	for (auto it: m) {
		ans += it.second - 1;
	}
	std::cout << ans;
}