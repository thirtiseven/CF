#include <iostream>
#include <deque>

int t, n;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		if (n < 4) {
			std::cout << "-1\n";
		} else {
			std::deque<int> ans;
			ans.push_back(3);
			ans.push_back(1);
			ans.push_back(4);
			ans.push_back(2);
			for (int i = 5; i <= n; i++) {
				if (i % 2 == 0) {
					ans.push_back(i);
				} else {
					ans.push_front(i);
				}
			}
			for (auto it: ans) {
				std::cout << it << ' ';
			}
			std::cout << '\n';
		}
	}
}