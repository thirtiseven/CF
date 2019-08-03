#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::vector<int> w;
		int x;
		for (int i = 0; i < n; i++) {
			std::cin >> x;
			w.push_back(x);
		}
		std::sort(w.begin(), w.end());
		std::cout << std::min(n-2, w[n-2]-1) << '\n';
	}
}