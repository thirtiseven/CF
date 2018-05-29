#include <iostream>
#include <map>
#include <algorithm>

int main(int argc, char *argv[]) {  
	long long n, a, b;
	std::map<long long, long long> ans;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a >> b;
		ans[a] = b;
	}
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a >> b;
		ans[a] = std::max(b, ans[a]);
	}
	long long tot = 0;
	for (auto i: ans) {
		tot += i.second;
	}
	std::cout << tot;
}