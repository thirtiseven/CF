#include <iostream>
#include <string>
#include <vector>

int t, n;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		std::vector<int> ans;
		int x = 10;
		while (n) {
			if (n % x) {
				ans.push_back(n%x);
			}
			n -= n % x;
			x *= 10;
		}
		std::cout << ans.size() << '\n';
		for (auto it: ans) {
			std::cout << it << ' ';
		}
		std::cout << '\n';
	}
}