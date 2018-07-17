#include <iostream>
#include <set>
#include <map>

int main(int argc, char *argv[]) {  
	std::multiset<int> a;
	int n, t[100007];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> t[i];
		a.insert(t[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (std::lower_bound(a.begin(), a.end(), t[i]) != a.end()) {
			a.erase(std::lower_bound(a.begin(), a.end(), t[i]));
			ans++;
		}
	}
	std::cout << ans;
}