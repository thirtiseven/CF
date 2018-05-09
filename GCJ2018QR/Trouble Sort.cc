#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int T, cnt = 1;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		int t;
		std::vector<int> a, b, c;
		for (int i = 0; i < n; i++) {
			std::cin >> t;
			if (i%2) {
				a.push_back(t);
			} else {
				b.push_back(t);
			}
			c.push_back(t);
		}
		std::sort(a.begin(), a.end());
		std::sort(b.begin(), b.end());
		std::sort(c.begin(), c.end());
		std::cout << "Case #" << cnt << ": ";
		cnt++;
		for(int i = 0; i < n; i++) {
			if(c[i] != (i%2?a[i/2]:b[i/2])) {
				std::cout << i << '\n';
				break;
			}
			if (i == n-1) {
				std::cout << "OK\n";
			}
		}
	}	
}